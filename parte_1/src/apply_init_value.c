#include "ep1.h"

void	apply_init_value(double **u, data *info, double (*func)(double))
{
	int		i;

	i = 0;
	while (i <= info->N)
	{
		u[0][i] = func(i * info->d_x);
		i++;
	}
}
