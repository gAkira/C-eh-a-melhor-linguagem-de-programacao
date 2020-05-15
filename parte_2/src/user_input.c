#include "../inc/ep1.h"

/*
** get user input values for M and N
*/

void	user_input(data *info)
{
	printf("Digite um valor para N:\t");
	scanf("%d", &(info->N));

#	if defined(EULER) || defined(CRANK_NICOLSON)
	printf("Digite um valor para M:\t");
	scanf("%d", &(info->M));
#	else
	int		i;
	
	if ((info->A_D = (double*)malloc((info->N - 1) * sizeof(double))))
	{
		printf("Digite os valores para a diagonal principal:\n");
		i = 1;
		while (i < info->N)
		{
			printf("A[%d][%d]: ", i, i);
			scanf("%lf", &(info->A_D[i - 1]));
			i++;
		}
	}
	if ((info->A_L = (double*)malloc((info->N - 2) * sizeof(double))))
	{
		printf("Digite os valores para as diagonais laterais:\n");
		i = 1;
		while (i < (info->N - 1))
		{
			printf("A[%d][%d] = A[%d][%d]: ", i, i + 1, i + 1, i);
			scanf("%lf", &(info->A_L[i - 1]));
			i++;
		}
	}
#	endif

}
