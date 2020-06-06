#include "../inc/ep2.h"

/*
**	Print values of each point of u_T and u_k into file
*/

static bool	print_header(FILE *mignon, heat *u, data *info);
static bool	print_body(FILE *mignon, heat *u, data *info);

bool		print_uk_file(heat *u, data *info)
{
	FILE	*mignon;

	mignon = fopen(SAVE_FILE, "w");
	print_header(mignon, u, info);
	print_body(mignon, u, info);
	fclose(mignon);
	return (true);
}





static bool	print_header(FILE *mignon, heat *u, data *info)
{
	int		k;

	fprintf(mignon, "#EX\n");
	fprintf(mignon, "#T\n");
	fprintf(mignon, "#N\n");
	fprintf(mignon, "#M\n");
	fprintf(mignon, "#nf\n");
	fprintf(mignon, "#<p[k] \\n>\n");
	fprintf(mignon, "#%c\n", info->ex);
	fprintf(mignon, "#%f\n", T);
	fprintf(mignon, "#%d\n", info->N);
	fprintf(mignon, "#%d\n", info->M);
	fprintf(mignon, "#%d\n", info->nf);
	k = 0;
	while (k < info->nf)
	{
		fprintf(mignon, "#%e\n", info->p[k]);
		k++;
	}
	fprintf(mignon, "#x_i | u_T(x_i) | a_k | u_k(x_i) | a_k*u_k(x_i)\n");
	return (true);
}

static bool	print_body(FILE *mignon, heat *u, data *info)
{
	int		i;
	int		k;

	i = 0;
	while (i <= info->N)
	{
		fprintf(mignon, "%e %e", i * info->d_x, u->u_T[i]);
		k = 0;
		while (k < info->nf)
		{
			fprintf(mignon, " %e %e %e", u->a_k[k], u->u_k[k][i],
							u->a_k[k] * u->u_k[k][i]);
			k++;
		}
		fprintf(mignon, "\n");
		i++;
	}
	return (true);
}
