#include "ep1.h"

/*
** uses method 11 of the subject to calculate new heat distribution
*/

void	calc_u_new(heat *u, data *info, int k)
{
	int		i;

	i = 1;
	while (i < info->N)
	{
		u->new[i] = u->old[i] + info->d_t * (((u->old[i - 1] - 2 * u->old[i] +
					u->old[i + 1]) / pow(info->d_x, 2.0)) +
					info->f(i * info->d_x, (k - 1) * info->d_t));
		i++;
	}
	u->new[0] = info->g1(k * info->d_t);
	u->new[info->N] = info->g2(k * info->d_t);
}
