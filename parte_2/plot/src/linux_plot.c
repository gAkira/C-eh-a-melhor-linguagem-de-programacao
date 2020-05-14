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

#include <fcntl.h>
#include "../../inc/ep1.h"
#include "../inc/get_next_line.h"

extern int	USER_N;
extern int	USER_M;

int		main(int argc, char *argv[])
{
	FILE	*gnuplot;
	int		fd_heat;
	char	*line;

	gnuplot = popen("gnuplot -persistent", "w");
	if (argc == 2 && argv[1][0] == '0')
	{
		fd_heat = open(LOCAL_D DATA_D HEAT_F, O_RDONLY);

		fprintf(gnuplot, "set title 'HEATMAP' \n");
		fprintf(gnuplot, "unset key \n");
		fprintf(gnuplot, "set xrange [0:%f] \n", T);
		fprintf(gnuplot, "set xlabel 'time' \n");
		fprintf(gnuplot, "set ylabel 'length' \n");
		fprintf(gnuplot, "set zlabel 'heat' \n");
		fprintf(gnuplot, "splot '-' u 1:2:3 w pm3d\n");
		fflush(gnuplot);
		while (get_next_line(fd_heat, &line) > 0)
		{
			fprintf(gnuplot, "%s \n", line);
			fflush(gnuplot);
			free(line);
		}
		fprintf(gnuplot, "e");
		fflush(gnuplot);
		close(fd_heat);
	}
	else if (argc == 2 && argv[1][0] == '1')
	{
		fprintf(gnuplot, "set title 'ERROR OVER TIME' \n");
		fprintf(gnuplot, "set xrange [0:%f] \n", T);
		fprintf(gnuplot, "set xlabel 'time' \n");
		fprintf(gnuplot, "set ylabel 'error' \n");
		fprintf(gnuplot, "plot '%s' u 1:2:3 w l lw 3 title 'diff',		\
							'' u 1:3 w l lw 3 title 'truncation' \n",	\
							LOCAL_D DATA_D ERROR_F);
		fflush(gnuplot);
	}
	else
		printf("Usage: ./plot [option]\t// 0 = heat map ; 1 = error graph\n");
	pclose(gnuplot);
	return (0);
}
