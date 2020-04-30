#include "ep1.h"

void	user_input(input *val)
{
	printf("Digite um valor para N:\t");
	scanf("%d", &(val->N));
	printf("Digite um valor para M:\t");
	scanf("%d", &(val->M));
}
