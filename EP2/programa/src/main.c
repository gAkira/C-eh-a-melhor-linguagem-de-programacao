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

int		main(void)
{
	heat	u;
	data	info;

	user_input(&info);
	process_info(&u, &info);
	crank_nicolson(&u, &info);
	set_uT(&u, &info);
	//solve_ak(&u, &info);
	//print_uk_file(&u, &info);

	//for (int i = 0; i < info.nf; i++)
	//	for (int k = 0; k <= info.N; k++)
	//		printf("u_T[%d] = %f\n", k, u.u_T[k]);
	//		printf("p[%d] = %f\t|\tuk[%d][%d] = %f\n",i , info.p[i], i, k, u.u_k[i][k]);
	return (0);
}
