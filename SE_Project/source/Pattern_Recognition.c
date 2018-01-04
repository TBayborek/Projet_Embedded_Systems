#include "Pattern_Recognition.h"

move Detect_Move(void) {
	// ----------- Variable Init ----------------
	posx = posy = posx_old = posy_old = 0;
	dx = dy = init_dx = init_dy = n_corners = init = i = 0;
	dangle = max_dangle_init = dist_last_edge = 0;

	memset(pos,0,sizeof(pos[0][0])*100*3);
	memset(angles_corner,0,sizeof(angles_corner[0])*4);

	n_points = start_draw = -1;
	min_dist_edge = 30.0;
	min_edge_ctrl_len = 10.0;
	// --------- End Variable Init --------

	/*
	BG_PALETTE_SUB[0] = ARGB16(1,0,0,0);
	BG_PALETTE_SUB[1] = ARGB16(1,31,0,0);
	memset(BG_BMP_RAM_SUB(26),0,256*192*2);
	//u16* bg3Map = (u16*) BG_BMP_RAM_SUB(26);
	 */

	while(1) {
		touchRead(&touch);
		posx = touch.px;
		posy = touch.py;

		if (posx || posy){
			touchRead(&touch);
			posx = touch.px;
			posy = touch.py;

			if (!(posx_old || posy_old)) n_points = 0;
			if (n_points>=0){
				dx = (int) posx - (int) posx_old;
				dy = (int) posy - (int) posy_old;
			}

			if ((dx || dy) && (n_points>=0)){
				start_draw = 1;
				n_points++;
				if(n_points>1){
					dist_last_edge += sqrt(pow(dx,2) + pow(dy,2));
					int nsteps = 50;
					//for(i=0;i<=nsteps;i++) VRAM_A[(int) floor((posy_old+dy*i/nsteps)*256+posx_old+dx*i/nsteps)] = ARGB16(1,0,0,0);
				}

				for(i=1;i<n_elems(pos);i++){
					pos[n_elems(pos)-i][0]=pos[n_elems(pos)-i-1][0];
					pos[n_elems(pos)-i][1]=pos[n_elems(pos)-i-1][1];
					pos[n_elems(pos)-i][2]=pos[n_elems(pos)-i-1][2];
				}
				pos[0][0] = posx;
				pos[0][1] = posy;
				if(n_points==1)pos[0][2] = 0;
				else pos[0][2] = sqrt(pow(dx,2) + pow(dy,2));

				double dist_new = 0.0, dist_old = 0.0;
				int last_index_new, last_index_old;
				for(i=0;i<n_elems(pos);i++){
					if (dist_new<min_edge_ctrl_len){
						dist_new+= pos[i][2];
						last_index_new = i;
					}
					else if(dist_old<min_edge_ctrl_len){
						dist_old+= pos[i][2];
						last_index_old = i;
					}
				}
				if (dist_new>min_edge_ctrl_len && dist_old>min_edge_ctrl_len){
					disp_x_new = pos[0][0] - pos[last_index_new+1][0];
					disp_y_new = pos[0][1] - pos[last_index_new+1][1];

					disp_x_old = pos[last_index_new+1][0] - pos[last_index_old+1][0];
					disp_y_old = pos[last_index_new+1][1] - pos[last_index_old+1][1];

					if (init==0){
						init_dx = disp_x_old;
						init_dy = disp_y_old;
						init = 1;
					}
					dangle = Vectors_Angle(disp_x_new,disp_y_new,disp_x_old,disp_y_old);

					if (Vectors_Angle(disp_x_new,disp_y_new,init_dx,init_dy)>max_dangle_init) max_dangle_init = Vectors_Angle(disp_x_new,disp_y_new,init_dx,init_dy);
				}

				double alpha_tresh = PI/4;
				if (!(fabs(dangle)<alpha_tresh || fabs(dangle+2*PI)<alpha_tresh || fabs(dangle-2*PI)<alpha_tresh)){
					if(dist_last_edge>min_dist_edge){
						if(n_corners<n_elems(angles_corner)) angles_corner[n_corners] = dangle;
						n_corners++;
						dist_last_edge = 0;
					}
				}
			}
			posx_old = posx;
			posy_old = posy;
		}
		else if(start_draw==1) start_draw = 0;

		if(start_draw == 0){
			double sum_angles;
			switch(n_corners){
				case 0:
					if ((Vectors_Angle(init_dx,init_dy, disp_x_new, disp_y_new)<PI/6) && (max_dangle_init>3*PI/4)) drawn_figure = ROCK;
					else drawn_figure = ERROR;
					break;
				case 1:
					if (angles_corner[0] > PI/2) drawn_figure = SCISSORS;
					else drawn_figure = ERROR;
					break;
				case 3:
					sum_angles = 0;
					for(i=0;i<3;i++) sum_angles+=angles_corner[i];
					if (sum_angles>5/4*PI) drawn_figure = PAPER;
					else drawn_figure = ERROR;
					break;
				case 4:
					sum_angles = 0;
					for(i=0;i<4;i++) sum_angles+=angles_corner[i];
					if ((Vectors_Angle(init_dx,init_dy, disp_x_new, disp_y_new)<PI/6) && (sum_angles>3/2*PI)) drawn_figure = PAPER;
					else drawn_figure = ERROR;
					break;
				default: drawn_figure = ERROR;
			}
			start_draw = -1;
			return drawn_figure;
		}
		swiWaitForVBlank();
	}
}

double Vectors_Angle(int v1x, int v1y,int v2x, int v2y){
	double scalar_prod = v1x*v2x+v1y*v2y;
	double norm_v1 = sqrt(pow(v1x,2) + pow(v1y,2));
	double norm_v2 = sqrt(pow(v2x,2) + pow(v2y,2));

	return acos(scalar_prod/(norm_v1*norm_v2));
}
