/******************************************************************************\
**        EP2 - MAP3121        .-------.     ,-----.      .---.    .-./`)     **
** --------------------------  \  _(`)_ \  .'  .-,  '.    | ,_|    \ .-.')    **
** Authors:                    | (_ o._)| / ,-.|  \ _ \ ,-./  )    / `-' \    **
** Guilherme Akira A. Santos   |  (_,_) /;  \  '_ /  | :\  '_ '`)   `-'`"`    **
** Leticia Mendonca Carraro    |   '-.-' |  _`,/ \ _/  | > (_)  )   .---.     **
**                             |   |     : (  '\_/ \   ;(  .  .-'   |   |     **
** NUSPs:                      |   |      \ `"/  \  ) /  `-'`-'|___ |   |     **
** 11027484                    /   )       '. \_/``".'    |        \|   |     **
** 10374480                    `---'         '-----'      `--------`'---'     **  
\******************************************************************************/

#include "../inc/ep2.h"

static void	print_info(heat *u, data *info);

int			main(void)
{
	heat	u;
	data	info;
	
	srand(time(0));
	user_input(&info);
	process_info(&u, &info);
	crank_nicolson(&u, &info);
	set_uT(&u, &info);
	solve_ak(&u, &info);
	calc_uTk(&u, &info);
	calc_E2(&u, &info);
	print_uk_file(&u, &info);
	print_info(&u, &info);
	free_mem(&u, &info);
	return (0);
}





static void	print_info(heat *u, data *info)
{
	int		k;
	
	printf("+----------------------+------------------------------------------+\n");
	printf("| %-20s | %-40c |\n", "Exercicio", info->ex );
	printf("+----------------------+------------------------------------------+\n");
	printf("| %-20s | %-40d |\n", "T", (int)T);
	printf("| %-20s | %-40d |\n", "N", info->N);
	printf("| %-20s | %-40d |\n", "M", info->M);
	printf("| %-20s | %-40.4g |\n", "lambda", info->lambda);
	printf("| %-20s | %-40d |\n", "nf", info->nf);
	printf("+-------+--------------+-------------+----------------------------+\n");
	printf("| %-5s | %-26s | %-26s |\n", "k", "p_k", "a_k");
	printf("+-------+----------------------------+----------------------------+\n");
	k = 0;
	while (k < info->nf)
	{
		printf("| %-5d | %-26g | %-26g |\n", k + 1, info->p[k], u->a_k[k]);
		k++;
	}
	printf("+-------+--------------+-------------+----------------------------+\n");
	printf("| %-20s | %-40.4g |\n", "Erro quadratico (E2)", u->E2);
	printf("+----------------------+------------------------------------------+\n");

}
