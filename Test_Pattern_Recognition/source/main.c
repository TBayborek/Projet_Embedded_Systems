#include <nds.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159265

enum figure{
			ROCK=0,
			SCISSORS=1,
			PAPER=2,
			ERROR=3,
};

#define n_elems(x) sizeof(x)/sizeof(x[0])

double mean(double x[],int array_len){
					int s, num_notnan=0; double sum=0;
					for(s=0;s<array_len;s++){
						if (!isnan(x[s])){
							sum+=x[s];
							num_notnan++;
						}
					}
					if(isnan(sum/num_notnan)) return 0;
					else return sum/num_notnan;
}

double vectors_angle(int v1x, int v1y,int v2x, int v2y){
	double scalar_prod = v1x*v2x+v1y*v2y;
	double norm_v1 = sqrt(pow(v1x,2) + pow(v1y,2));
	double norm_v2 = sqrt(pow(v2x,2) + pow(v2y,2));

	return acos(scalar_prod/(norm_v1*norm_v2));
}

//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	REG_DISPCNT = MODE_FB0;
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_LCD;
	REG_POWERCNT ^= BIT(15);
	memset(VRAM_A,0xFF,256*192*2);

	u16 posx, posy, posx_old, posy_old;
	int dx, dy, init_dx, init_dy, n_corners, n_points, init, i;
	int disp_x_new, disp_y_new, disp_x_old, disp_y_old;
	int start_draw = -1;
	double pos[100][3], angles_corner[4], dangle, max_dangle_init, dist_last_edge;
	double min_dist_edge = 30;
	double min_edge_ctrl_len = 8;
	touchPosition touch;

	enum figure drawn_figure;

	dx = dy = n_corners = posx_old = posy_old = dangle = dist_last_edge = init = max_dangle_init = 0;
	n_points = -1;

	consoleDemoInit();


	while(1) {
		scanKeys();
		unsigned keys = keysHeld();
		if (keys & KEY_A) main();


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
					int nsteps = 20;
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
					printf("dangle: %f\n", dangle);

					if (vectors_angle(disp_x_new,disp_y_new,init_dx,init_dy)>max_dangle_init) max_dangle_init = vectors_angle(disp_x_new,disp_y_new,init_dx,init_dy);
				}

				double alpha_tresh = PI/4;
				if (!(fabs(dangle)<alpha_tresh || fabs(dangle+2*PI)<alpha_tresh || fabs(dangle-2*PI)<alpha_tresh)){
					if(dist_last_edge>min_dist_edge){
						if(n_corners<n_elems(angles_corner)) angles_corner[n_corners] = dangle;
						n_corners++;
						dist_last_edge = 0;

						printf("number of corners: %i\n",n_corners);
						printf("\n\n");

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
					printf("max dangle init %f \n", max_dangle_init);
					if ((vectors_angle(init_dx,init_dy, disp_x_new, disp_y_new)<PI/4) && (max_dangle_init>3*PI/4)) drawn_figure = ROCK;
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
			printf("drawn_figure: %u\n",drawn_figure);
			start_draw = -1;
		}

		swiWaitForVBlank();
	}
}
