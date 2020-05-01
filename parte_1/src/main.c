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

void    print_into_file(FILE *fd, double *u, int k, data *info);

int		main(void)
{
	int		k;
	FILE	*fd;
	data	info;
	heat	u;

	user_input(&info);
	process_info(&info, &fonte, &fronteira_1, &fronteira_2);
	fd = fopen("./plot/bololo.haha", "w");
	if (!(u.old = ((double*)malloc((info.N + 1) * sizeof(double)))))
	{
		fclose(fd);
		return (1);
	}
	apply_init_value(&u, &info, &init_value);
	print_into_file(fd, u.old, 0, &info);
	k = 1;
	while (k <= info.M)
	{
		if (!(u.new = (double*)malloc((info.N + 1) * sizeof(double))))
		{
			free(u.old);
			fclose(fd);
			return (1);
		}
		calc_u_new(&u, &info, k);
		print_into_file(fd, u.new, k, &info);
		free(u.old);
		u.old = u.new;
		k++;
	}
	free(u.old);
	fclose(fd);
	return (0);
}

void	print_into_file(FILE *fd, double *u, int k, data *info)
{
	int		i;

	i = 0;
	while (i <= info->N)
	{
		fprintf(fd, "%f %f %f\n", k * info->d_t, i * info->d_x, u[i]);
		i++;
	}
}
