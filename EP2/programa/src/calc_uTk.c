#include "../inc/ep2.h"

/*
** Calculate the aproximated solution to u_T
*/

bool	calc_uTk(heat *u, data *info)
{
	int		i;
	int		k;

	u->u_Tk = (double*)malloc((info->N + 1) * sizeof(double));
	i = 0;
	while (i <= info->N)
	{
		k = 0;
		u->u_Tk[i] = 0.0;
		while (k < info->nf)
		{
			u->u_Tk[i] += u->a_k[k] * u->u_k[k][i];
			k++;
		}
		i++;
	}
	return (true);
}
