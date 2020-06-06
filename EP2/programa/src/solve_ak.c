#include "../inc/ep2.h"

/*
**	Function that solves the normal matrix for a_k given in the subject
*/

static double	inner_prod(double *u, double *v, int size);
static bool		ldl_decomp(heat *u, data *info);

bool			solve_ak(heat *u, data *info)
{
	int		i;
	int		k;
	double	sum;
	double	*z;

	ldl_decomp(u, info);
	z = (double*)malloc(info->nf * sizeof(double));
	u->a_k = (double*)malloc(info->nf * sizeof(double));
	i = 0;
	while (i < info->nf)	/* L.z = b */
	{
		sum = 0.0;
		k = 0;
		while (k < i)
		{
			sum += u->L[i][k] * z[k];
			k++;
		}
		z[i] = inner_prod(u->u_T, u->u_k[i], info->N) - sum;
		i++;
	}
	i = 0;
	while (i < info->nf)	/* D.y = z */
	{
		z[i] /= u->D[i];
		i++;
	}
	i = info->nf - 1;
	while (i >= 0)	/* Lt.a_k = y */
	{
		sum = 0.0;
		k = info->nf - 1;
		while (k > i)
		{
			sum += u->L[k][i] * u->a_k[k];
			k--;
		}
		u->a_k[i] = z[i] - sum;
		i--;	
	}
	free(z);
	free(u->D);
	i = 0;
	while (i < info->nf)
	{
		free(u->L[i]);
		i++;
	}
	free(u->L);
	return (true);
}





static double	inner_prod(double *u, double *v, int size)
{
	int		i;
	double	sum;

	i = 1;
	sum = 0.0;
	while (i < size)
	{
		sum += u[i] * v[i];
		i++;
	}
	return (sum);
}

static bool	ldl_decomp(heat *u, data *info)
{
	int		i;
	int		j;
	int		k;
	double	sum;

	u->D = (double*)malloc(info->nf * sizeof(double));
	u->L = (double**)malloc(info->nf * sizeof(double*));
	i = 0;
	while (i < info->nf)
	{
		u->L[i] = (double*)malloc((i + 1) * sizeof(double));
		u->L[i][i] = 1.0;
		i++;
	}
	j = 0;
	while (j < info->nf)
	{
		sum = 0.0;
		k = 0;
		while (k < j)
		{
			sum += pow(u->L[j][k], 2.0) * u->D[k];
			k++;
		}
		u->D[j] = inner_prod(u->u_k[j], u->u_k[j], info->N) - sum;
		i = j + 1;
		while (i < info->nf)
		{
			sum = 0.0;
			k = 0;
			while (k < j)
			{
				sum += u->L[i][k] * u->D[k] * u->L[j][k];
				k++;
			}
			u->L[i][j] = (inner_prod(u->u_k[i], u->u_k[j], info->N) - sum)
							* (1.0 / u->D[j]);
			i++;
		}
		j++;
	}
	return (true);
}
