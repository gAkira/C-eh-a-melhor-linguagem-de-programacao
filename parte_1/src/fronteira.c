#include "../inc/ep1.h"

/*
** write the functions that describe your boundary conditions
** lower bound -> fronteira_1
** upper bound -> fronteira_2
*/

double	fronteira_1(double t)
{
	(void)t;
#	if defined(EX_A_FAKE) || defined(EX_A)
	return (0.0);
#	elif defined(EX_B)
	return (exp(t));
#	elif defined(EX_C_1) || defined(EX_C_2)
	return (0.0);
#	else
	return (-10E6);
#	endif
}

double	fronteira_2(double t)
{
	(void)t;
#	if defined(EX_A_FAKE) || defined(EX_A)
	return (0.0);
#	elif defined(EX_B)
	return (exp(t - 1.0) * cos(5.0 * t));
#	elif defined(EX_C_1) || defined(EX_C_2)
	return (0.0);
#	else
	return (-10E6);
#	endif
}
