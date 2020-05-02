#include "ep1.h"

/*
** calculates the error between the result that we got and the solution
** then calculates truncation error
*/

static double	max_err(double *err, int size);

bool			calc_error(heat *u, data *info, double (*func)(double, double), int k)
{
	int		i;
	double	*err;
	double	*trunc;

	i = 0;
	if (!(err = (double*)malloc((info->N + 1) * sizeof(double))))
		return (false);
	if (k && !(trunc = (double*)malloc((info->N - 1) * sizeof(double))))
	{
		free(err);
		return (false);
	}
	while (i <= info->N)
	{
		err[i] = abs((k ? u->new[i] : u->old[i]) -
									func(k * info->d_t, i * info->d_x));
		if (k > 0 && k <= info->M && i > 0 && i < info->N)
			trunc[i - 1] = abs(((u->new[i] - u->old[i]) / info->d_t) -
				((u->old[i - 1] - 2 * u->old[i] + u->old[i + 1]) /
					pow(info->d_x, 2)) -
					info->f((k - 1) * info->d_t, i * info->d_x));
		i++;
	}
	u->error[k] = max_err(err, info->N + 1);
	if (k)
		u->trunc[k - 1] = max_err(trunc, info->N - 1);
	if (k == info->M)
		u->trunc_max = max_err(u->trunc, info->M);
	free(err);
	if (k)
		free (trunc);
	return (true);
}

static double	max_err(double *err, int size)
{
	int		i;
	double	max;

	i = 1;
	max = err[0];
	while (i < size)
	{
		if (err[i] > max)
			max = err[i];
		i++;
	}
	return (max);
}
