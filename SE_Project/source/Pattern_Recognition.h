#include "Define.h"
#include "Shared.h"

u16 posx, posy, posx_old, posy_old;
int dx, dy, init_dx, init_dy, n_corners, n_points, init, start_draw, i;
int disp_x_new, disp_y_new, disp_x_old, disp_y_old;
double pos[100][3], angles_corner[4], dangle, max_dangle_init, dist_last_edge;
double min_dist_edge = 30;
double min_edge_ctrl_len = 10;
touchPosition touch;
move drawn_figure;

move detect_move(void);
double vectors_angle(int, int, int, int);
