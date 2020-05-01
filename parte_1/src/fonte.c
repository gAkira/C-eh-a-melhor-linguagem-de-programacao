#include "ep1.h"

/*
** write the function that describes your heat source
*/

double fonte(double t, double x)
{
	return ((10 * pow(x, 2.0) * (x - 1)) - (60 * x * t) + (20 * t));
}
