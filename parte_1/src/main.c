/******************************************************************************\
**        EP1 - MAP3121        .-------.     ,-----.      .---.    .-./`)     **
** --------------------------  \  _(`)_ \  .'  .-,  '.    | ,_|    \ .-.')    **
** Authors:                    | (_ o._)| / ,-.|  \ _ \ ,-./  )    / `-' \    **
** Guilherme Akira A. Santos   |  (_,_) /;  \  '_ /  | :\  '_ '`)   `-'`"`    **
** Leticia Mendonca Carraro    |   '-.-' |  _`,/ \ _/  | > (_)  )   .---.     **
**                             |   |     : (  '\_/ \   ;(  .  .-'   |   |     **
** NUSPs:                      |   |      \ `"/  \  ) /  `-'`-'|___ |   |     **
** 11027484                    /   )       '. \_/``".'    |        \|   |     **
** 10374480                    `---'         '-----'      `--------`'---'     **  
\******************************************************************************/

#include "ep1.h"

int		main(void)
{
	input	value;
	data	info;
	double	**u;

	user_input(&value);
	process_info(&info, &value, &fonte);
	if (!create_matrix(&u, value.M + 1, value.N + 1))
		return (1);
	apply_init_value(u, &info, &init_value);

/*	PRINTA MATRIZ U NO TERMINAL
	for (int i = 0; i < value.M + 1; i++)
	{
		for (int k = 0; k < value.N + 1; k++)
			printf("%f\t", u[i][k]);
		printf("\n");
	}
*/
	return (0);
}
