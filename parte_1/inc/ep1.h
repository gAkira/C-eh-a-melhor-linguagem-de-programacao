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
# include "../../p1.h"

# define LOCAL_D "./"
# define PLOT_D "plot/"
# define DATA_D "data/"
# define WLOCAL_D ".\\"
# define WPLOT_D "plot\\"
# define WDATA_D "data\\"

# if defined(EX_A_FAKE)
#  define HEAT_F "EXP_A_FAKE.heat"
#  define HEAT_TITLE "TEMPERATURA - EXPLICITO: EX(A_v_a_l_i_d_a_c_a_o)"
#  define ERROR_F "EXP_A_FAKE.error"
#  define ERROR_TITLE "ERRO - EXPLICITO: EX(A_v_a_l_i_d_a_c_a_o)"
# elif defined(EX_A)
#  define HEAT_F "EXP_A.heat"
#  define HEAT_TITLE "TEMPERATURA - EXPLICITO: EX(A)"
#  define ERROR_F "EXP_A.error"
#  define ERROR_TITLE "ERRO - EXPLICITO: EX(A)"
# elif defined(EX_B)
#  define HEAT_F "EXP_B.heat"
#  define HEAT_TITLE "TEMPERATURA - EXPLICITO: EX(B)"
#  define ERROR_F "EXP_B.error"
#  define ERROR_TITLE "ERRO - EXPLICITO: EX(B)"
# elif defined(EX_C_1)
#  define HEAT_F "EXP_C_CONST.heat"
#  define HEAT_TITLE "TEMPERATURA - EXPLICITO: EX(C_d_i_s_t_r_ _c_o_n_s_t)"
# elif defined(EX_C_2)
#  define HEAT_F "EXP_C_LINEAR.heat"
#  define HEAT_TITLE "TEMPERATURA - EXPLICITO: EX(C_d_i_s_t_r_ _l_i_n_e_a_r)"
# endif

# if defined(EX_C_1) || defined(EX_C_2)
#  if defined(CALC_ERROR)
#   undef CALC_ERROR
#  endif
# endif

int	USER_N;
int	USER_M;

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
	double	error_max;
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
