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
# define CALC_ERROR true

# define LOCAL_D "./"
# define PLOT_D "plot/"
# define DATA_D "data/"
# define HEAT_F "bololo.haha"
# define ERROR_F "erroooo.ou"

typedef struct
{
	int		M;
	int		N;
	double	d_t;
	double	d_x;
	double	lambda;
	double	(*f)(double, double);
    double	(*g1)(double);
    double	(*g2)(double);
} data;

typedef struct
{
    double	*old;
    double	*new;
	double	*error;
	double	*trunc;
	double	trunc_max;
} heat;

double	solution(double t, double x);
double	fonte(double t, double x);
double	fronteira_1(double t);
double	fronteira_2(double t);
double	init_value(double x);

void	user_input(data *info);
void	process_info(data *info, double (*func)(double, double),
						double (*frnt_1)(double), double (*frnt_2)(double));
void	apply_init_value(heat *u, data *info, double (*func)(double)); 
void	calc_u_new(heat *u, data *info, int k);
bool	calc_error(heat *u, data *info, double (*func)(double, double), int k);

#endif
