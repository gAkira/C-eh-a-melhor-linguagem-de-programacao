#include "../inc/ep1.h"

/*
** get user input values for M and N
*/

void	user_input(data *info)
{
	printf("Digite um valor para N: ");
	scanf("%d", &(info->N));
	printf("Digite um valor para lambda: ");
	scanf("%lf", &(info->lambda));
}
