#include "../inc/ep1.h"

/*
** write the function that describes your initial heat distribution u_0
*/

double	init_value(double x)
{
	(void)x;
#	if defined(EX_A_FAKE)
	return (0.0);
#	elif defined(EX_A)
	return (pow(x, 2.0) * pow(1 - x, 2.0));
#	elif defined(EX_B)
	return (exp(-x));
#	elif defined(EX_C_1) || defined(EX_C_2)
	return (0.0);
#	else
	return (-10E6);
#	endif
}
