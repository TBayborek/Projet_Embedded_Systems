#include "Define.h"
#include "Shared.h"

u16 posx, posy, posx_old, posy_old;
int dx, dy, init_dx, init_dy, n_corners, n_points, init, start_draw, i;
int disp_x_new, disp_y_new, disp_x_old, disp_y_old;
double pos[100][3], angles_corner[4], dangle, max_dangle_init, dist_last_edge;
double min_dist_edge, min_edge_ctrl_len;
touchPosition touch;
move drawn_figure;

// main function that detects the pattern
move Detect_Move(void);

// function that calculates the angle between two vectors given their x,y component
double Vectors_Angle(int, int, int, int);
