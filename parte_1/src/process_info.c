#include "ep1.h"

void	process_info(data *info, input *val, double (*func)(double, double))
{
	info->M = val->M;
	info->N = val->N;
	info->d_x = 1.0 / val->N;
	info->d_t = T / val->M;
	info->lambda = (info->d_t)/(pow(info->d_x, 2.0));
	info->f = func;
}
