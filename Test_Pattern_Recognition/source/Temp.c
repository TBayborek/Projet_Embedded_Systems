				/*

				if (n_points>n_elems(distances)){
					double distances_half_new[n_elems(distances)/2];
					double distances_half_old[n_elems(distances)-n_elems(distances)/2];
					for(i=0;i<n_elems(distances_half_new);i++) distances_half_new[i]=distances[i];
					for(j=0;j<n_elems(distances_half_old);j++) distances_half_old[j]=distances[i+j];

					angle_mean_new = mean(distances_half_new,n_elems(distances_half_new));
					angle_mean_old = mean(distances_half_old,n_elems(distances_half_old));

					dangle = angle_mean_new - angle_mean_old;
					double alpha_tresh = PI/6;

					if (!(fabs(dangle)<alpha_tresh || fabs(dangle+2*PI)<alpha_tresh || fabs(dangle-2*PI)<alpha_tresh)){
						if (((n_points-n_points_last_edge)>n_elems(distances)/2) && (edge_trigger == false)){
							n_edge++;
							n_points_last_edge=n_points;
							edge_trigger = true;

							printf("mean_new: %f\n",angle_mean_new);
							for(i=0;i<n_elems(angles_half_new);i++) printf("%f ",angles_half_new[i]);
							printf("\n\n");
							printf("mean_old: %f\n",angle_mean_old);
							for(i=0;i<n_elems(angles_half_old);i++) printf("%f ",angles_half_old[i]);
							printf("\n\n");
							printf("number of edges: %i\n",n_edge);
							printf("trigger at %u points",n_points_last_edge);
							printf("\n\n\n");
							for(i=0;i<10;i++)VRAM_A[posy*256+posx+i] = ARGB16(1,31,0,0);

						}
					}
					else edge_trigger = false;

				}
				//printf("mean: %f\n",mean(angles,n_elems(angles)));
				//printf("mean1: %f\n",angle_mean_1);
				//printf("mean2: %f\n",angle_mean_2);
				//printf("posx: %u\nposy: %u\n",posx,posy);
				//printf("dx: %i\ndy: %i\n",dx,dy);
				//printf("dangle: %f\n",def_angle(dx,dy));
				//printf("dangle: %f\n",dangle);
				//printf("number of edges: %i\n",n_edge);
				//printf("number of points: %i\n", n_points);
				//printf("\n\n");
				 */
