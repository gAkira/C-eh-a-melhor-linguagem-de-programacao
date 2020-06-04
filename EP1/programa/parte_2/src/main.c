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

void	print_ldl(heat *u, data *info);
void	print_header_file(FILE *fd, data *info);
void    print_heat_file(FILE *fd, double *u, int k, data *info);
void    print_error_file(FILE *fd, heat *u, data *info);
void	print_info(heat *u, data *info);

int		main(void)
{
	int		k;
	FILE	*fd_u;	/* heat distribution file */
	data	info;
	heat	u;

	user_input(&info);
	process_info(&info, &fonte, &fronteira_1, &fronteira_2);
	ldl_decomp(&u, &info);

#	if defined(SHOW_DECOMP)
	print_ldl(&u, &info);
#		if !defined(EULER) && !defined(CRANK_NICOLSON)
	free(info.A_D);
	free(info.A_L);
	free(u.D);
	free(u.L);
	return (0);
#		endif
#	endif

	if (getenv("OS"))
		fd_u = fopen(WLOCAL_D WPLOT_D WDATA_D HEAT_F, "w");
	else
		fd_u = fopen(LOCAL_D PLOT_D DATA_D HEAT_F, "w");
	if (!(u.old = (double*)malloc((info.N + 1) * sizeof(double))))
	{
		fclose(fd_u);
		return (1);
	}
	print_header_file(fd_u, &info);
	apply_init_value(&u, &info, &init_value);
	print_heat_file(fd_u, u.old, 0, &info);

#	if defined(CALC_ERROR)
	FILE	*fd_e;	/* error file */

	if (getenv("OS"))
		fd_e = fopen(WLOCAL_D WPLOT_D WDATA_D ERROR_F, "w");
	else
		fd_e = fopen(LOCAL_D PLOT_D DATA_D ERROR_F, "w");
	print_header_file(fd_e, &info);
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

	free(info.A_D);
	free(info.A_L);
	free(u.old);
	fclose(fd_u);

#	if defined(CALC_ERROR)
	print_error_file(fd_e, &u, &info);
	free(u.error);
	free(u.trunc);
	fclose(fd_e);
#	endif

	print_info(&u, &info);
	return (0);
}

void	print_ldl(heat *u, data *info)
{
	int		i;

	printf("\n");
	printf("Itens da diagonal D[]:\n{");
	i = 0;
	while (i < (info->N - 1))
	{
		printf("%g", u->D[i]);
		i == (info->N - 2) ? printf("}\n") : printf(" , ");
		i++;
	}
	printf("Itens das diagonais laterais L[]:\n{");
	i = 0;
	while (i < (info->N - 2))
	{
		printf("%g", u->L[i]);
		i == (info->N - 3) ? printf("}\n") : printf(" , ");
		i++;
	}
	printf("\n");
}

void	print_header_file(FILE *fd, data *info)
{
#	if !defined(EX_C_1) && !defined(EX_C_2)
	fprintf(fd, "#T=%.2g N=%d M=%d\n", T, info->N, info->M);
#	else
	fprintf(fd, "#T=%.2g N=%d M=%d P=%.2g\n", T, info->N, info->M, P);
#	endif
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

void    print_error_file(FILE *fd, heat *u, data *info)
{
	int		k;

	k = 0;
	while (k <= info->M)
	{
		fprintf(fd, "%e %e %e %e\n", k * info->d_t, u->error[k], u->error_max,
					u->trunc_max);
		k++;
	}
}

void	print_info(heat *u, data *info)
{

	(void)u;
	printf("+----------------------+------------------------------------------+\n");

#	if defined(EULER)
	printf("| %-20s | %-40s |\n", "Metodo", "Implicito: Euler");
#	elif defined(CRANK_NICOLSON)
	printf("| %-20s | %-40s |\n", "Metodo", "Implicito: Crank-Nicolson");
#	endif

	printf("+----------------------+------------------------------------------+\n");

#	if defined(EX_A_FAKE)
	printf("| %-20s | %-40s |\n", "Exercicio", "1.a - Validacao");
#	elif defined(EX_A)
	printf("| %-20s | %-40s |\n", "Exercicio", "1.a");
#	elif defined(EX_B)
	printf("| %-20s | %-40s |\n", "Exercicio", "1.b");
#	elif defined(EX_C_1)
	printf("| %-20s | %-40s |\n", "Exercicio", "1.c - Distr. 'const.' no dominio");
#	elif defined(EX_C_2)
	printf("| %-20s | %-40s |\n", "Exercicio", "1.c - Distr. 'linear' no dominio");
#	endif

	printf("+----------------------+------------------------------------------+\n");
	printf("| %-20s | %-40d |\n", "T", (int)T);
	printf("| %-20s | %-40d |\n", "N", info->N);
	printf("| %-20s | %-40d |\n", "M", info->M);
	printf("| %-20s | %-40.4g |\n", "lambda", info->lambda);

#	if defined(EX_C_1) || defined(EX_C_2)
	printf("| %-20s | %-40.4g |\n", "P", P > 0.0 && P < 1.0 ? P : 0.25);
#	endif

	printf("+----------------------+------------------------------------------+\n");

#	if defined(CALC_ERROR)
	printf("| %-20s | %-40.4g |\n", "Erro max truncamento", u->trunc_max);
	printf("| %-20s | %-40.4g |\n", "Erro max", u->error_max);
	printf("+----------------------+------------------------------------------+\n");
#	endif

}

