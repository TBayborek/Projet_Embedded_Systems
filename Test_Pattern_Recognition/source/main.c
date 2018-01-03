#include <nds.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

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


double def_angle(int x, int y){
	if(x == 0) return y/abs(y)*PI/2;
	else if(y == 0) return (1-x/abs(x))/2*PI;
	else return atan((double) y/(double) x);
}

/*
void shift_array(double &a[],int n_row, ,int n_col, int n_shifts){
	return 0;
}
*/

//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	REG_DISPCNT = MODE_FB0;
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_LCD;
	REG_POWERCNT ^= BIT(15);
	memset(VRAM_A,0xFF,256*192*2);

	u16 posx, posy, posx_old, posy_old;
	int dx, dy, n_edge, n_points, i;
	double pos[20][3], dangle, dist_last_edge;
	dx = dy = n_edge = posx_old = posy_old = dangle = dist_last_edge = 0;
	double min_dist_edge = 50;
	n_points = -1;

	touchPosition touch;

	consoleDemoInit();

	while(1) {
		scanKeys();
		unsigned keys = keysHeld();

		if (keys & KEY_TOUCH){
			touchRead(&touch);
			posx = touch.px;
			posy = touch.py;

			if (!(posx_old || posy_old)) n_points = 0;
			if (n_points>=0){
				dx = (int) posx - (int) posx_old;
				dy = (int) posy - (int) posy_old;
			}

			if ((dx || dy) && (n_points>=0)){
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
					if (dist_new<min_dist_edge){
						dist_new+= pos[i][2];
						last_index_new = i;
					}
					else if(dist_old<min_dist_edge){
						dist_old+= pos[i][2];
						last_index_old = i;
					}
				}

				if (dist_new>min_dist_edge && dist_old>min_dist_edge){
					double disp_x_new = pos[0][0] - pos[last_index_new+1][0];
					double disp_y_new = pos[0][1] - pos[last_index_new+1][1];
					double angle_new = def_angle(disp_x_new,disp_y_new);

					double disp_x_old = pos[last_index_new][0] - pos[last_index_old+1][0];
					double disp_y_old = pos[last_index_new][1] - pos[last_index_old+1][1];
					double angle_old = def_angle(disp_x_old,disp_y_old);

					dangle = angle_new - angle_old;
					//printf("dangle: %f\n",dangle);
					//printf("a_new: %f a_old: %f\n",angle_new,angle_old);
				}


				double alpha_tresh = PI/6;
				if (!(fabs(dangle)<alpha_tresh || fabs(dangle+2*PI)<alpha_tresh || fabs(dangle-2*PI)<alpha_tresh)){
					if(dist_last_edge>min_dist_edge){
						n_edge++;
						dist_last_edge = 0;

						printf("number of edges: %i\n",n_edge);
						printf("\n\n");
					}
				}
			}
			posx_old = posx;
			posy_old = posy;
		}
		swiWaitForVBlank();
	}
}
