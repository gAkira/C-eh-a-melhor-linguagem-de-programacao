#include "../inc/ep1.h"

/*
** uses implicit method of EULER or CRANK_NICOLSON of the subject to build the
** linear system and then solve it with the Cholesky method for LDLt decomp
*/

void	calc_u_new(heat *u, data *info, int k)
{
	int		i;
	double	lmbd;
	double	*z;

	(void)lmbd;
	u->new[0] = info->g1(k * info->d_t);
	u->new[info->N] = info->g2(k * info->d_t);
	z = (double*)malloc((info->N - 1) * sizeof(double));
	i = 1;
	while (i <= (info->N - 1))	/* L.z = b */
	{
#		if defined(EULER)
		lmbd = info->lambda;
		z[i - 1] = u->old[i] + info->d_t * info->f(k * info->d_t, i * info->d_x)
				+ (i == (info->N - 1) ? lmbd * info->g2(k * info->d_t) : 0.0) 
				+ (i == 1 ? lmbd * info->g1(k * info->d_t) :
							-(u->L[i - 2] * z[i - 2]));
#		elif defined(CRANK_NICOLSON)
		lmbd = info->lambda / 2.0;
		z[i - 1] = (1.0 - 2.0 * lmbd) * u->old[i]
				+ lmbd * (u->old[i - 1] + u->old[i + 1])
				+ ((info->d_t / 2.0)
				* (info->f((k - 1) * info->d_t, i * info->d_x)
				+ info->f(k * info->d_t, i * info->d_x)))
				+ (i == info->N - 1 ? lmbd * u->new[info->N] : 0.0) 
				+ (i == 1 ? lmbd * u->new[0] : -u->L[i - 2] * z[i - 2]);
#		endif
		i++;
	}
	i = 1;
	while (i <= (info->N - 1)) /* D.y = z */
	{
		z[i - 1] /= u->D[i - 1];
		i++;
	}
	i = info->N - 1;
	while (i >= 1)	/* Lt.x = y */
	{
		u->new[i] = z[i - 1] + (i == (info->N - 1) ? 0.0 :
										-(u->L[i - 1] * u->new[i + 1]));
		i--;
	}
	free(z);
}
