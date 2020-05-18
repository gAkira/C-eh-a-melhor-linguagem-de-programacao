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
	return ((10.0 * pow(x, 2.0) * (x - 1.0)) - (60.0 * x * t) + (20.0 * t));
#	elif defined(EX_A)
	return ((10.0 * cos(10.0 * t) * pow(x, 2.0) * pow(1.0 - x, 2.0)) -
			((1.0 + sin(10.0 * t)) * (12.0 * pow(x, 2.0) - (12.0 * x) + 2.0)));
#	elif defined(EX_B)
	return (5.0 * exp(t - x) * ((5.0 * pow(t, 2.0) * cos(5.0 * t * x)) -
			((2.0 * t + x) * sin(5.0 * t * x))));
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
	return (10000.0 * (1.0 - 2.0 * pow(t, 2.0)));
}
#endif

#if defined(EX_C_1)
static double	gh_1(double x)
{
	double	point_p;
	double	h;

	h = 1.0 / (double)USER_N;
	point_p = (P > 0.0 && P < 1.0) ? P : 0.25;
	if((x >= (point_p - h / 2.0)) && (x <= (point_p + h / 2.0)))
		return (1.0 / h);
	return (0.0);
}
#endif

#if defined(EX_C_2)
static double	gh_2(double x)
{
	double	point_p;
	double	h;

	h = 1.0 / (double)USER_N;
	point_p = (P > 0.0 && P < 1.0) ? P : 0.25;
	if (x >= (point_p - h) && x <= point_p)
		return ((1.0 / pow(h, 2.0)) * (x - (point_p - h)));
	else if (x > point_p && x <= (point_p + h))
		return (-(1.0 / pow(h, 2.0)) * (x - (point_p + h)));
	else
		return (0.0);
}
#endif
