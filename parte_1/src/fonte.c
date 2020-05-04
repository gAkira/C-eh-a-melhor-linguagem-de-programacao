#include "../inc/ep1.h"

extern int		USER_N;
extern int		USER_M;

/*
** aux functions to EX_C_x
*/

#if defined(EX_C_1) || defined(EX_C_2)
static double	r(double t);
# if defined(EX_C_1)
static double	gh_1(double x);
# else
static double	gh_2(double x);
# endif
#endif

/*
** write the function that describes your heat source
*/

double			fonte(double t, double x)
{
	(void)t;
	(void)x;
#	if defined(EX_A_FAKE)
	return ((10 * pow(x, 2.0) * (x - 1)) - (60 * x * t) + (20 * t));
#	elif defined(EX_A)
	return ((10 * cos(10 * t) * pow(x, 2.0) * pow(1 - x, 2.0)) -
			(1 + sin(10 * t)) * (12 * pow(x, 2.0) - 12 * x + 2));
#	elif defined(EX_B)
	return (5 * exp(t - x) * ((5 * pow(t, 2.0) * cos(5 * t * x)) -
			((2 * t + x) * sin(5 * t * x))));
#	elif defined(EX_C_1)
	return (r(t) * gh_1(x));
#	elif defined(EX_C_2)
	return (r(t) * gh_2(x));
#	else
	return (-10E6);
#	endif
}

#if defined(EX_C_1) || defined(EX_C_2)
static double	r(double t)
{
	return (10000 * (1 - 2 * pow(t, 2.0)));
}
#endif

#if defined(EX_C_1)
static double	gh_1(double x)
{
	if((x >= (P - (double)USER_N / 2.0)) && (x <= (P + (double)USER_N / 2.0)))
		return (1.0 / (double)USER_N);
	return (0.0);
}
#endif

#if defined(EX_C_2)
static double	gh_2(double x)
{
	if (x >= (P - USER_N) && x <= P)
		return ((1.0 / pow((double)USER_N, 2.0)) * (x - (P - (double)USER_N)));
	else if (x > P && x <= (P + (double)USER_N))
		return (-(1.0 / pow((double)USER_N, 2.0)) * (x - (P + (double)USER_N)));
	else
		return (0.0);
}
#endif
