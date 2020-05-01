#include "ep1.h"

/*
** applies the initial heat distribution u_0 (u.old)
*/

void	apply_init_value(heat *u, data *info, double (*func)(double))
{
	int		i;

	i = 0;
	while (i <= info->N)
	{
		u->old[i] = func(i * info->d_x);
		i++;
	}
}
