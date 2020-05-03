#include "../inc/ep1.h"

/*
** get user input values for M and N
*/

void	user_input(data *info)
{
	printf("Digite um valor para N:\t");
	scanf("%d", &(info->N));
	printf("Digite um valor para M:\t");
	scanf("%d", &(info->M));
}
