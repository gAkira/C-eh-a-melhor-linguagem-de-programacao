#include "../inc/ep1.h"

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

	if (!(err = (double*)malloc((info->N + 1) * sizeof(double))))
		return (false);
	if (k < info->M && !(trunc = (double*)malloc((info->N - 1) * sizeof(double))))
	{
		free(err);
		return (false);
	}
	i = 1;
	while (i > 0 && i < info->N)
	{
		err[i] = fmax(fabs(func(k * info->d_t, i * info->d_x) -
						(k ? u->new[i] : u->old[i])),
						fabs((k ? u->new[i] : u->old[i]) -
						func(k * info->d_t, i * info->d_x)));
		if (k < info->M && i > 0 && i < info->N)
			trunc[i - 1] = fabs(((func((k + 1) * info->d_t, i * info->d_x) -
					func(k * info->d_t, i * info->d_x)) / info->d_t) -
					((func((k + 1) * info->d_t, (i - 1) * info->d_x) -
					2 * func((k + 1) * info->d_t, i * info->d_x) + 
					func((k + 1) * info->d_t, (i + 1) * info->d_x)) /
					pow(info->d_x, 2.0)) -
					info->f((k + 1) * info->d_t, i * info->d_x));
		i++;
	}
	u->error[k] = max_err(err, info->N + 1);
	if (k < info->M)
	{
		u->trunc[k] = max_err(trunc, info->N - 1);
		free(trunc);
	}
	else
	{
		u->error_max = max_err(u->error, (info->M + 1));
		u->trunc_max = max_err(u->trunc, info->M);
	}
	free(err);
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
