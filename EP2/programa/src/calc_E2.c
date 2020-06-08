#include "../inc/ep2.h"

/*
** Calculate the mean squared error
*/

void	calc_E2(heat *u, data *info)
{
	int		i;
	double	sum;

	i = 1;
	sum = 0.0;
	while (i < info->N)
	{
		sum += pow(u->u_T[i] - u->u_Tk[i], 2.0);
		i++;
	}
	u->E2 = sqrt(info->d_x * sum);
}

