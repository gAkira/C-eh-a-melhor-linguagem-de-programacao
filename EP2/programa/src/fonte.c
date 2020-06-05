#include "../inc/ep2.h"

/*
** function that describes your heat source
*/

extern int		USER_N;
extern int		USER_M;

static double	r(double t);
double	gh(double x, double p);

double			fonte(double t, double x, double p)
{
	return (r(t) * gh(x, p));
}





static double	r(double t)
{
	return (10.0 * (1.0 + cos(5.0 * t)));
}

double	gh(double x, double p)
{
	double	h;

	h = 1.0 / (double)USER_N;
	if((x >= (p - h / 2.0)) && (x <= (p + h / 2.0)))
		return (1.0 / h);
	return (0.0);
}

