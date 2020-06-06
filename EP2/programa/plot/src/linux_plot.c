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

#include "../../inc/ep2.h"
#include "../inc/get_next_line.h"

int		main(int argc, char *argv[])
{
	FILE	*gnuplot;
	int		fd;
	char	ex;
	//double	T;
	int		N;
	int		M;
	int		nf;
	double	*p;
	char	*line;
	char	*file;

	gnuplot = popen("gnuplot -persistent", "w");
	file = (argc == 2) ? argv[1] : "./"SAVE_FILE;
	fd = open(file, O_RDONLY);

	fprintf(gnuplot, "set title '%s' \n", "SOLUÇÃO DO PROBLEMA INVERSO");
	//get_next_line(fd, &line);
	//fprintf(gnuplot, "set label '%s' at screen 0.46, 0.925 font 'Arial,8'\n", &line[1]);
	//free(line);
	for (int i = 0 ; i < 6 ; i++)
	{
		get_next_line(fd, &line);
		free(line);
	}
	get_next_line(fd, &line);
	ex = line[1];
	free(line);

	get_next_line(fd, &line);
	//T = atof(&line[1]);
	free(line);
	
	get_next_line(fd, &line);
	N = atoi(&line[1]);
	free(line);
	
	get_next_line(fd, &line);
	M = atoi(&line[1]);
	free(line);
	
	get_next_line(fd, &line);
	nf = atoi(&line[1]);
	free(line);
	
	p = (double*)malloc(nf * sizeof(double));
	for (int i = 0 ; i < nf ; i++)
	{
		get_next_line(fd, &line);
		p[i] = atof(&line[1]);
		free(line);
	}
	close(fd);

	fprintf(gnuplot, "set xlabel 'length' \n");
	fprintf(gnuplot, "set ylabel 'heat' \n");
	fprintf(gnuplot, "plot '%s' u 1:2 w l lw 3 title 'u_T(x)'", file);
	for (int i = 0 ; i < nf ; i++)
	{
		fprintf(gnuplot, ", '%s' u 1:%d w l lw 1.5 title 'u_%d(x)'", file, 3 * i + 3 + 2, i);
	}
	fprintf(gnuplot, "\n");
	fflush(gnuplot);
	pclose(gnuplot);
	free(p);
	return (0);
}
