#include "../inc/ep2.h"

/*
** get user input values
*/

bool	user_input(data *info)
{
	printf("+-----------------------------------------------------------------+\n");
	printf("| %-63s |\n", "a) Teste: 1 fonte - solucao trivial");
	printf("| %-63s |\n", "b) Teste: 4 fontes - validacao do sistema linear");
	printf("| %-63s |\n", "c) Arquivo: carrega dados de teste.txt");
	printf("| %-63s |\n", "d) Ruido: carrega dados com ruidos de teste.txt");
	printf("+-----------------------------------------------------------------+\n\n");
	
	printf("Selecione o exercicio desejado: ");
	scanf("%c", &(info->ex));
	if (info->ex == 'c' || info->ex == 'd')
	{
		printf("Digite um valor para N: ");
		scanf("%d", &(info->N));
	}
	else
		info->N = 128;
	info->M = info->N;
	printf("\n");
	return (true);
}
