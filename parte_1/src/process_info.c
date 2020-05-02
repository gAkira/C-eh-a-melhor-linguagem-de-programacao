#include "ep1.h"

/*
** build the 'data' structure
*/
extern int	GRID_N;
extern int	GRID_M;

void	process_info(data *info, double (*func)(double, double),
                        double (*frnt_1)(double), double (*frnt_2)(double))
{
	GRID_N = info->N;
	GRID_M = info->M;
	info->d_x = 1.0 / info->N;
	info->d_t = T / info->M;
	info->lambda = (info->d_t)/(pow(info->d_x, 2.0));
	info->f = func;
    info->g1 = frnt_1;
    info->g2 = frnt_2;
}
