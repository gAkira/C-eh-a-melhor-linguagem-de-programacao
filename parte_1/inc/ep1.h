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

#ifndef EP1_H
# define EP1_H

# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define T 1.0

typedef struct
{
	int		M;
	int		N;
} input;

typedef struct
{
	int		M;
	int		N;
	double	d_t;
	double	d_x;
	double	lambda;
	double	(*f)(double, double);
} data;

double	fonte(double t, double x);
double	init_value(double x);

void	user_input(input *val);
void	process_info(data *info, input *val, double (*func)(double, double));
bool	create_matrix(double ***m, int rows, int cols);
void	apply_init_value(double **m, data *info, double (*func)(double)); 

#endif
