/* This file is used in order to detect the drawings made on the sub screen on the Nintendo ds.
 * The algorithm tracks every points that are drawn and takes two sequences of points and creates an approximated vector
 * for each of the sequences and checks the angle between the two vectors. If the angles is higher than a given threshold than
 * it considers it as an edge. At the end of a pattern according to the number of edges and some other criteria it determines
 * which pattern has been drawn.
 *
 * Different patterns are recognized :
	 * Circle = ROCK
	 * Square = PAPER
	 * V-Shape = SCISSORS
 */

#include "Pattern_Recognition.h"
#include "Game_Update.h"

move Detect_Move(void) {
	//------------ Activation BG3 ---------------
	REG_DISPCNT_SUB |= DISPLAY_BG3_ACTIVE;
	// ----------- Variable Init ----------------
	posx = posy = posx_old = posy_old = 0;
	dx = dy = init_dx = init_dy = n_corners = init = i = 0;
	dangle = max_dangle_init = dist_last_edge = 0;

	memset(pos,0,sizeof(pos[0][0])*100*3); // will contain the x-position, y-position, distanced traveled since the last point. For each point
	memset(angles_corner,0,sizeof(angles_corner[0])*4); // will contain for each detected edge the angle

	n_points = start_draw = -1;
	min_dist_edge = 30.0; // minimum distance before detecting a new corner
	min_edge_ctrl_len = 8; // minimum length of each vector
	// --------- End Variable Init --------

	while(1) {
		Handle_Button(); // Check if user pressed START => PAUSE
		if(times_up || Game_Status == PAUSE){drawn_figure = ERROR; break;} // if times up or user paused, exit loop

		touchRead(&touch);
		posx = touch.px;
		posy = touch.py;

		// if the position is different than 0,0 and within the drawing area, handle the drawing
		if ((posx || posy) && (posx>=0) && (posx<256) && (posy>=0) && (posy<192)){

			if (!(posx_old || posy_old)) n_points = 0; // initialize the number of points to 0 the first time
			if (n_points>=0){
				dx = (int) posx - (int) posx_old; // Displacement on the x-axis from the previous point
				dy = (int) posy - (int) posy_old; // Displacement on the y-axis from the previous point
			}

			// if there is a displacement
			if ((dx || dy) && (n_points>=0)){
				start_draw = 1; // The drawing starts
				n_points++; // increment number of points
				if(n_points>1){ // for the first point there is no displacement to calculate
					dist_last_edge += sqrt(pow(dx,2) + pow(dy,2)); // add the traveled distance
					int nsteps = 100;
					if (posy<180){ // Draw the points with linear interpolation between two last points
						for(i=0;i<=nsteps;i++) bg3Map_SUB[(int) floor((posy_old+dy*i/nsteps)*256+posx_old+dx*i/nsteps)] = ARGB16(1,0,0,0);
					}
				}

				// Update the position matrix with new information
				for(i=1;i<n_elems(pos);i++){ //shift all the information one row below
					pos[n_elems(pos)-i][0]=pos[n_elems(pos)-i-1][0];
					pos[n_elems(pos)-i][1]=pos[n_elems(pos)-i-1][1];
					pos[n_elems(pos)-i][2]=pos[n_elems(pos)-i-1][2];
				}
				pos[0][0] = posx; // add all the new information on the first row.
				pos[0][1] = posy;
				if(n_points!=1) pos[0][2] = sqrt(pow(dx,2) + pow(dy,2));

				// Create the two sequences (new/old)
				double dist_new = 0.0, dist_old = 0.0; // length of the two sequences, new/old sequence of points
				int last_index_new, last_index_old; // index of the last point belonging to the new/old sequence
				for(i=0;i<n_elems(pos);i++){ // for each point
					if (dist_new<min_edge_ctrl_len){ // until the length of the sequence is not long enough
						dist_new+= pos[i][2]; // add the traveled distance between the two points
						last_index_new = i; // store the index of the point, the last stored index will correspond to the last index of the sequence
					}
					else if(dist_old<min_edge_ctrl_len){ // The new sequence is long enough, now do the same for the old sequence
						dist_old+= pos[i][2];
						last_index_old = i;
					}
				}

				// Approximate sequences with vectors and calculate angle
				if (dist_new>min_edge_ctrl_len && dist_old>min_edge_ctrl_len){ // if both sequences are long enough
					// Create vectors with their x and y component
					disp_x_new = pos[0][0] - pos[last_index_new+1][0]; // Calculate the distance on the x-axis between the first and last point in the new sequence
					disp_y_new = pos[0][1] - pos[last_index_new+1][1]; // Same on y-axis

					disp_x_old = pos[last_index_new+1][0] - pos[last_index_old+1][0]; // Same for old sequence
					disp_y_old = pos[last_index_new+1][1] - pos[last_index_old+1][1];

					if (init==0){ // Store the initial vector
						init_dx = disp_x_old;
						init_dy = disp_y_old;
						init = 1;
					}
					// Calculate angle between the two vectors
					dangle = Vectors_Angle(disp_x_new,disp_y_new,disp_x_old,disp_y_old);

					// Store the highest angle between the initial vector and the next ones
					if (Vectors_Angle(disp_x_new,disp_y_new,init_dx,init_dy)>max_dangle_init) max_dangle_init = Vectors_Angle(disp_x_new,disp_y_new,init_dx,init_dy);
				}

				// Check if there is a corner
				double alpha_tresh = PI/4; // Angle threshold to detect edge
				if (!(fabs(dangle)<alpha_tresh || fabs(dangle+2*PI)<alpha_tresh || fabs(dangle-2*PI)<alpha_tresh)){ // if the angle is higher than the threshold
					if(dist_last_edge>min_dist_edge){ // if the distance since the last corner is greater than the threshold
						if(n_corners<n_elems(angles_corner)) angles_corner[n_corners] = dangle; // Store the angle of the corner
						n_corners++;
						dist_last_edge = 0;
					}
				}
			}
			// Store the position
			posx_old = posx;
			posy_old = posy;
		}
		else if(start_draw==1) start_draw = 0; // if drawing started and touch not detected => drawing is finished

		// if the drawing is finished
		if(start_draw == 0){
			double sum_angles;
			switch(n_corners){ // Verify the number of corners detected
				case 0: // ROCK?
					// if the vectors angle between the start and end of drawing is below a threshold and a vector in the drawing was above a threshold
					if ((Vectors_Angle(init_dx,init_dy, disp_x_new, disp_y_new)<PI/4) && (max_dangle_init>3*PI/4)) drawn_figure = ROCK;
					else drawn_figure = ERROR;
					break;
				case 1: // SCISSORS?
					// if the angle of the first corner is above a threshold
					if (angles_corner[0] > PI/2) drawn_figure = SCISSORS;
					else drawn_figure = ERROR;
					break;
				case 3: // Paper
					// if the sum of all the angles is above a threshold
					sum_angles = 0;
					for(i=0;i<3;i++) sum_angles+=angles_corner[i];
					if (sum_angles>5/4*PI) drawn_figure = PAPER;
					else drawn_figure = ERROR;
					break;
				case 4: // Paper
					// if the sum of all the angles is above a threshold and the vectors angle between the start and end of drawing is below a threshold
					sum_angles = 0;
					for(i=0;i<4;i++) sum_angles+=angles_corner[i];
					if ((Vectors_Angle(init_dx,init_dy, disp_x_new, disp_y_new)<PI/6) && (sum_angles>3/2*PI)) drawn_figure = PAPER;
					else drawn_figure = ERROR;
					break;
				default: drawn_figure = ERROR; // else figure not recognized => ERROR
			}
			break;
		}
		swiWaitForVBlank();
	}
	// Clean the background and return the figure
	memset(bg3Map_SUB, ARGB16(0,0,0,0),256*185*2);
	REG_DISPCNT_SUB &= ~DISPLAY_BG3_ACTIVE;
	return drawn_figure;
}

// Checks the angle between two vectors, for given x,y components
// uses the scalar product property a*b = ||a||*||b||*cos(alpha)
double Vectors_Angle(int v1x, int v1y,int v2x, int v2y){
	double scalar_prod = v1x*v2x+v1y*v2y;
	double norm_v1 = sqrt(pow(v1x,2) + pow(v1y,2));
	double norm_v2 = sqrt(pow(v2x,2) + pow(v2y,2));

	return acos(scalar_prod/(norm_v1*norm_v2));
}
