#include "../inc/ep1.h"

/*
** Makes the LDLt decomposition
*/

void	ldl_decomp(heat *u, data *info)
{
	int		i;

	if ((u->D = (double*)malloc((info->N - 1) * sizeof(double))) &&
			(u->L = (double*)malloc((info->N - 2) * sizeof(double))))
	{
		i = 0;
		while (i < (info->N - 1))
		{
			u->D[i] = (i ? info->A_D[i] - (pow(u->L[i - 1], 2.0) * u->D[i - 1])
						: info->A_D[i]);
			if (i < (info->N - 2))
				u->L[i] = info->A_L[i] / u->D[i]; 
			i++;
		}
	}
}
