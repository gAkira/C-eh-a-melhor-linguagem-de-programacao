#include "../inc/ep1.h"

double	solution(double t, double x)
{
	(void)t;
	(void)x;
#	if defined(EX_A_FAKE)
	return (10.0 * t * pow(x, 2.0) * (x - 1.0));
#	elif defined(EX_A)
	return ((1.0 + sin(10.0 * t)) * pow(x, 2.0) * pow(1.0 - x, 2.0));
#	elif defined(EX_B)
	return (exp(t - x) * cos(5.0 * t * x));
#	else
	return (-10E6);
#	endif
}
