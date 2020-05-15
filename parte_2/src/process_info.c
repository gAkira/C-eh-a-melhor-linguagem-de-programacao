#include "../inc/ep1.h"

/*
** build the 'data' structure
*/

extern int	USER_N;
extern int	USER_M;

void	process_info(data *info, double (*func)(double, double),
                        double (*frnt_1)(double), double (*frnt_2)(double))
{
	USER_N = info->N;
	USER_M = info->M;
	info->d_x = 1.0 / info->N;
	info->d_t = T / info->M;
	info->lambda = (info->d_t) / (pow(info->d_x, 2.0));
	info->f = func;
    info->g1 = frnt_1;
    info->g2 = frnt_2;

#	if defined(EULER)
	int		i;

	if ((info->A_D = (double*)malloc((info->N - 1) * sizeof(double))))
	{
		i = 1;
		while (i < info->N)
		{
			info->A_D[i - 1] = 1.0 + 2 * info->lambda;
			i++;
		}
	}
	if ((info->A_L = (double*)malloc((info->N - 2) * sizeof(double))))
	{
		i = 1;
		while (i < (info->N - 1))
		{
			info->A_L[i - 1] = -info->lambda;
			i++;
		}
	}
#	elif defined(CRANK_NICOLSON)
	int		i;

	if ((info->A_D = (double*)malloc((info->N - 1) * sizeof(double))))
	{
		i = 1;
		while (i < info->N)
		{
			info->A_D[i - 1] = 1.0 + info->lambda;
			i++;
		}
	}
	if ((info->A_L = (double*)malloc((info->N - 2) * sizeof(double))))
	{
		i = 1;
		while (i < (info->N - 1))
		{
			info->A_L[i - 1] = -(info->lambda / 2.0);
			i++;
		}
	}
#	endif

}
