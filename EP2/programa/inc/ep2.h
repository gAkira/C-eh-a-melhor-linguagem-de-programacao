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

#ifndef EP2_H
# define EP2_H

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

# define DATA_FILE "teste.txt"

typedef struct
{
	char	ex;
	int		M;
	int		N;
	int		nf;
	double	d_t;
	double	d_x;
	double	lambda;
	double	*p;
	double	(*f)(double, double, double);
    double	(*g1)(double);
    double	(*g2)(double);
} data;

typedef struct
{
	double	*u_T;
	double	*a_k;
	double	**u_k;
} heat;

typedef struct
{
    double	*old;
    double	*new;
} c_n;

double	fonte(double t, double x, double p);
double	fronteira_1(double t);
double	fronteira_2(double t);
double	init_value(double x);

bool	user_input(data *info);
bool	process_info(data *info);
bool	crank_nicolson(heat *u, data *info);
bool	solve_ak(heat *u, data *info);

#endif
