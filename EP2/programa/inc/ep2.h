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

# include <ctype.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "get_next_line.h"

# define T 1.0
# define NAME_FILE "teste.txt"
# define N_FILE 2048
# define SAVE_FILE "lulz.lol"

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
	double	E2;
	double	*D;
	double	**L;
	double	*u_T;
	double	*a_k;
	double	**u_k;
	double	*u_Tk;
} heat;

typedef struct
{
	double	*D;
	double	*L;
    double	*old;
    double	*new;
} c_n;

int	USER_N;
int	USER_M;

double	fonte(double t, double x, double p);
double	fronteira_1(double t);
double	fronteira_2(double t);
double	init_value(double x);

bool	user_input(data *info);
bool	process_info(heat *u, data *info);
bool	crank_nicolson(heat *u, data *info);
bool	set_uT(heat *u, data *info);
bool	solve_ak(heat *u, data *info);
bool	calc_uTk(heat *u, data *info);
void	calc_E2(heat *u, data *info);
bool	print_uk_file(heat *u, data *info);
bool	free_mem(heat *u, data *info); 

#endif
