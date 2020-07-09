#include "../inc/ep2.h"

/*
** Calculate the approximated solution to u_T
*/

bool	calc_uTk(heat *u, data *info)
{
	int		i;
	int		k;

	u->u_Tk = (double*)malloc((info->N + 1) * sizeof(double));
	u->u_Tk[0] = fronteira_1(T);
	u->u_Tk[info->N] = fronteira_2(T);
	i = 1;
	while (i < info->N)
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
