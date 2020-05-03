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

#include "../../inc/ep1.h"

extern int	GRID_N;
extern int	GRID_M;

int		main(int argc, char *argv[])
{
	FILE	*gnuplot;

	gnuplot = _popen("gnuplot -persistent", "w");
	if (argc == 2 && argv[1][0] == '0')
	{
		fprintf(gnuplot, "set title 'HEAT MAP' \n");
		fprintf(gnuplot, "set dgrid %d,%d \n", GRID_M, GRID_N);
		fprintf(gnuplot, "set hidden3d \n");
		fprintf(gnuplot, "unset key \n");
		fprintf(gnuplot, "set xrange [0:%f] \n", T);
		fprintf(gnuplot, "set xlabel 'time' \n");
		fprintf(gnuplot, "set ylabel 'length' \n");
		fprintf(gnuplot, "set zlabel 'heat' \n");
		fprintf(gnuplot, "splot '%s' u 1:2:3 w l \n", LOCAL_D DATA_D HEAT_F);
		fflush(gnuplot);
	}
	else if (argc == 2 && argv[1][0] == '1')
	{
		fprintf(gnuplot, "set title 'ERROR OVER TIME' \n");
		fprintf(gnuplot, "set xrange [0:%f] \n", T);
		fprintf(gnuplot, "set xlabel 'time' \n");
		fprintf(gnuplot, "set ylabel 'error' \n");
		fprintf(gnuplot, "plot '%s' u 1:2 w l lw 3 title 'diff', \
						'%s' u 1:3 w l lw 3 title 'truncation'\n",
						LOCAL_D DATA_D ERROR_F, LOCAL_D DATA_D ERROR_F);
		fflush(gnuplot);
	}
	else
		printf("Usage: ./plot [option]\t// 0 = heat map ; 1 = error graph\n");
	pclose(gnuplot);
	return (0);
}
