#include "../inc/ep1.h"

double	solution(double t, double x)
{
	(void)t;
	(void)x;
#	if defined(EX_A_FAKE)
	return (10 * t * pow(x, 2) * (x - 1));
#	elif defined(EX_A)
	return ((1 + sin(10 * t)) * pow(x, 2.0) * pow(1 - x, 2.0));
#	elif defined(EX_B)
	return (exp(t - x) * cos(5 * t * x));
#	else
	return (-10E6);
#	endif
}
