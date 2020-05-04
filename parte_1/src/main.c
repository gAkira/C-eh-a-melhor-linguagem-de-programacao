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

#include "../inc/ep1.h"

void    print_heat_file(FILE *fd, double *u, int k, data *info);
void    print_error_file(FILE *fd, double *err, double trunc, data *info);

int		main(void)
{
	int		k;
	FILE	*fd_u;	/* heat distribution file */
	data	info;
	heat	u;

	user_input(&info);
	process_info(&info, &fonte, &fronteira_1, &fronteira_2);
	if (getenv("OS"))
		fd_u = fopen(WLOCAL_D WPLOT_D WDATA_D HEAT_F, "w");
	else
		fd_u = fopen(LOCAL_D PLOT_D DATA_D HEAT_F, "w");
	if (!(u.old = (double*)malloc((info.N + 1) * sizeof(double))))
	{
		fclose(fd_u);
		return (1);
	}
	apply_init_value(&u, &info, &init_value);
	print_heat_file(fd_u, u.old, 0, &info);

#	if defined(CALC_ERROR)
	FILE	*fd_e;	/* error file */

	if (getenv("OS"))
		fd_e = fopen(WLOCAL_D WPLOT_D WDATA_D ERROR_F, "w");
	else
		fd_e = fopen(LOCAL_D PLOT_D DATA_D ERROR_F, "w");
	u.error = NULL;
	u.trunc = NULL;
	if (!(u.error = (double*)malloc((info.M + 1) * sizeof(double))) ||
		!(u.trunc = (double*)malloc((info.M) * sizeof(double))) ||
			!calc_error(&u, &info, &solution, 0))
	{
		free(u.old);
		if (u.error)
			free(u.error);
		if (u.trunc)
			free(u.trunc);
		fclose(fd_u);
		fclose(fd_e);
		return (1);
	}
#	endif

	k = 1;
	while (k <= info.M)
	{
		if (!(u.new = (double*)malloc((info.N + 1) * sizeof(double))))
		{
#			if defined(CALC_ERROR)
			free(u.error);
			free(u.trunc);
			fclose(fd_e);
#			endif

			free(u.old);
			fclose(fd_u);
			return (1);
		}
		calc_u_new(&u, &info, k);
		print_heat_file(fd_u, u.new, k, &info);

#		if defined(CALC_ERROR)
		calc_error(&u, &info, &solution, k);
#		endif

		free(u.old);
		u.old = u.new;
		k++;
	}

	free(u.old);
	fclose(fd_u);

#	if defined(CALC_ERROR)
	print_error_file(fd_e, u.error, u.trunc_max, &info);
	free(u.error);
	free(u.trunc);
	fclose(fd_e);
#	endif

	return (0);
}

void	print_heat_file(FILE *fd, double *u, int k, data *info)
{
	int		i;

	i = 0;
	while (i <= info->N)
	{
		fprintf(fd, "%e %e %e\n", k * info->d_t, i * info->d_x, u[i]);
		i++;
	}
	fprintf(fd, "\n");
}

void    print_error_file(FILE *fd, double *err, double trunc, data *info)
{
	int		k;

	k = 0;
	while (k <= info->M)
	{
		fprintf(fd, "%e %e %e\n", k * info->d_t, err[k], trunc);
		k++;
	}
}
