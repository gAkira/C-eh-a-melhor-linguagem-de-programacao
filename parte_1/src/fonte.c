#include "../inc/ep1.h"

/*
** write the function that describes your heat source
*/

double fonte(double t, double x)
{
	(void)t;
	(void)x;
#	if defined(EX_A_FAKE)
	return ((10 * pow(x, 2.0) * (x - 1)) - (60 * x * t) + (20 * t));
#	elif defined(EX_A)
	return ((10 * cos(10 * t) * pow(x, 2.0) * pow(1 - x, 2.0)) -
			(1 + sin(10 * t)) * (12 * pow(x, 2.0) - 12 * x + 2));
#	else
	return (-10E6);
#	endif
}
