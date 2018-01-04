#include "Pattern_Recognition.h"

move detect_move(void) {
	dx = dy = n_corners = posx_old = posy_old = dangle = dist_last_edge = init = max_dangle_init = 0;
	n_points = start_draw = -1;

	while(1) {
		scanKeys();
		unsigned keys = keysHeld();

		if ((keys & KEY_TOUCH)){
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
					for(i=0;i<=nsteps;i++) VRAM_A[(int) floor((posy_old+dy*i/nsteps)*256+posx_old+dx*i/nsteps)] = ARGB16(1,0,0,0);
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
					dangle = vectors_angle(disp_x_new,disp_y_new,disp_x_old,disp_y_old);

					if (vectors_angle(disp_x_new,disp_y_new,init_dx,init_dy)>max_dangle_init) max_dangle_init = vectors_angle(disp_x_new,disp_y_new,init_dx,init_dy);
				}

				double alpha_tresh = PI/4;
				if (!(fabs(dangle)<alpha_tresh || fabs(dangle+2*PI)<alpha_tresh || fabs(dangle-2*PI)<alpha_tresh)){
					if(dist_last_edge>min_dist_edge){
						if(n_corners<n_elems(angles_corner)) angles_corner[n_corners] = dangle;
						n_corners++;
						dist_last_edge = 0;

						for(i=-5;i<5;i++)VRAM_A[(int) (pos[last_index_new+1][1]*256+pos[last_index_new+1][0]+i)] = ARGB16(1,31,0,0);

						int ddx_n = pos[0][0] - pos[last_index_new+1][0];
						int ddy_n = pos[0][1] - pos[last_index_new+1][1];

						int ddx_o = pos[last_index_new+1][0] - pos[last_index_old+1][0];
						int ddy_o = pos[last_index_new+1][1] - pos[last_index_old+1][1];

						int nsteps=100;
						for(i=0;i<=nsteps;i++) {
							int posi_n = (int) floor((pos[last_index_new+1][1]+ddy_n*i/nsteps)*256+pos[last_index_new+1][0]+ddx_n*i/nsteps);
							int posi_o = (int) floor((pos[last_index_old+1][1]+ddy_o*i/nsteps)*256+pos[last_index_old+1][0]+ddx_o*i/nsteps);
							VRAM_A[posi_n] = ARGB16(1,0,0,31);
							VRAM_A[posi_o] = ARGB16(1,0,0,31);
						}


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
					if ((vectors_angle(init_dx,init_dy, disp_x_new, disp_y_new)<PI/6) && (max_dangle_init>3*PI/4)) drawn_figure = ROCK;
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
					if ((vectors_angle(init_dx,init_dy, disp_x_new, disp_y_new)<PI/6) && (sum_angles>3/2*PI)) drawn_figure = PAPER;
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


double vectors_angle(int v1x, int v1y,int v2x, int v2y){
	double scalar_prod = v1x*v2x+v1y*v2y;
	double norm_v1 = sqrt(pow(v1x,2) + pow(v1y,2));
	double norm_v2 = sqrt(pow(v2x,2) + pow(v2y,2));

	return acos(scalar_prod/(norm_v1*norm_v2));
}
