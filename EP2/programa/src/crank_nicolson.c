#include "../inc/ep2.h"

/*
** This function solves uk(T,x) for each fk at pk using Crank-Nicolson's method
*/

static bool	ldl_decomp(c_n *uk, data *info);
static void	apply_init_value(c_n *uk, data *info);
static bool	calc_uk_new(c_n *uk, data *info, int k, double p);

bool		crank_nicolson(heat *u, data *info)
{
	int		k;
	int		t;
	c_n		uk;
	
	ldl_decomp(&uk, info);
	k = 0;
	while (k < info->nf)
	{
		uk.old = (double*)malloc((info->N + 1) * sizeof(double));
		apply_init_value(&uk, info);
		t = 1;
		while (t <= info->M)
		{
			uk.new = (double*)malloc((info->N + 1) * sizeof(double));
			calc_uk_new(&uk, info, t, info->p[k]);
			free(uk.old);
			uk.old = uk.new;
			t++;
		}
		u->u_k[k] = uk.old;
		k++;
	}
	return (true);
}





static bool	ldl_decomp(c_n *uk, data *info)
{
	int		i;

	if ((uk->D = (double*)malloc((info->N - 1) * sizeof(double))) &&
			(uk->L = (double*)malloc((info->N - 2) * sizeof(double))))
	{
		i = 0;
		while (i < (info->N - 1))
		{
			uk->D[i] = (i ? (1.0 + info->lambda) - (pow(uk->L[i - 1], 2.0)
						* uk->D[i - 1]) : (1.0 + info->lambda));
			if (i < (info->N - 2))
				uk->L[i] = -(info->lambda / 2.0) / uk->D[i]; 
			i++;
		}
		return (true);
	}
	return (false);
}

static void	apply_init_value(c_n *uk, data *info)
{
	int		i;

	i = 0;
	while (i <= info->N)
	{
		uk->old[i] = init_value(i * info->d_x);
		i++;
	}
}

static bool	calc_uk_new(c_n *uk, data *info, int k, double p)
{
	int		i;
	double	lmbd;
	double	*z;

	uk->new[0] = info->g1(k * info->d_t);
	uk->new[info->N] = info->g2(k * info->d_t);
	z = (double*)malloc((info->N - 1) * sizeof(double));
	i = 1;
	while (i <= (info->N - 1))	/* L.z = b */
	{
		lmbd = info->lambda / 2.0;
		z[i - 1] = (1.0 - 2.0 * lmbd) * uk->old[i]
				+ lmbd * (uk->old[i - 1] + uk->old[i + 1])
				+ ((info->d_t / 2.0)
				* (info->f((k - 1) * info->d_t, i * info->d_x, p)
				+ info->f(k * info->d_t, i * info->d_x, p)))
				+ (i == info->N - 1 ? lmbd * uk->new[info->N] : 0.0) 
				+ (i == 1 ? lmbd * uk->new[0] : -uk->L[i - 2] * z[i - 2]);
		i++;
	}
	i = 1;
	while (i <= (info->N - 1)) /* D.y = z */
	{
		z[i - 1] /= uk->D[i - 1];
		i++;
	}
	i = info->N - 1;
	while (i >= 1)	/* Lt.x = y */
	{
		uk->new[i] = z[i - 1] + (i == (info->N - 1) ? 0.0 :
										-(uk->L[i - 1] * uk->new[i + 1]));
		i--;
	}
	free(z);
	return (true);
}

