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

static void	print_usage(void);
static char	process_options(char *argv);
static char	*my_itoa(int num);
static char	*small_text(int num);

int			main(int argc, char *argv[])
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
	char	*small;
	char	options;
	bool	started;

	if (argc < 2)
	{
		print_usage();
		return (0);
	}
	options = process_options(argv[1]);
	gnuplot = _popen("gnuplot -persistent", "w");
	file = ".\\data\\"SAVE_FILE;
	fd = open(file, O_RDONLY);
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

	fprintf(gnuplot, "set title 'SOLUCAO DO PROBLEMA INVERSO: EX(%c)' \n", toupper(ex));
	fprintf(gnuplot, "set label 'T=%g N=%d M=%d nf=%d' at screen 0.415, 0.925 font 'Arial,8'\n", T, N, M, nf);
	fprintf(gnuplot, "set xlabel 'length' \n");
	fprintf(gnuplot, "set ylabel 'heat' \n");
	fprintf(gnuplot, "set style line 2 lt 2 \n");
	started = false;
	if (ex == 'd' && options & 0b00000010)
	{	
		if (started)
			fprintf(gnuplot, ", '%s' u 1:3 w l lc 9 lw 2 title 'u_T__k(x)'", file);
		else
			fprintf(gnuplot, "plot '%s' u 1:3 w l lc 9 lw 2 title 'u_T__k(x)'", file);
		started = true;
	}
	if (options & 0b00000001)
	{
		double lw = (ex == 'd' ? 1 : 3);
		if (started)
			fprintf(gnuplot, ", '%s' u 1:2 w l lw %f title 'u_T(x)'", file, lw);
		else
			fprintf(gnuplot, "plot '%s' u 1:2 w l lw %f title 'u_T(x)'", file, lw);
		started = true;
	}
	if (ex != 'd' && options & 0b00000010)
	{	
		if (started)
			fprintf(gnuplot, ", '%s' u 1:3 w l lt 2 lw 2 title 'u_T__k(x)'", file);
		else
			fprintf(gnuplot, "plot '%s' u 1:3 w l lt 2 lw 2 title 'u_T__k(x)'", file);
		started = true;
	}
	if (options & 0b00000100)
	{
		for (int i = 0 ; i < nf ; i++)
		{
			small = small_text(i + 1);
			if (started)
				fprintf(gnuplot, ", '%s' u 1:%d w l lw 1.5 title 'a%s(x)'", file, 3 * i + 3 + 1, small);
			else
				fprintf(gnuplot, "plot '%s' u 1:%d w l lw 1.5 title 'a%s(x)'", file, 3 * i + 3 + 1, small);
			started = true;
			free(small);
		}
	}
	if (options & 0b00001000)
	{
		for (int i = 0 ; i < nf ; i++)
		{
			small = small_text(i + 1);
			if (started)
				fprintf(gnuplot, ", '%s' u 1:%d w l lw 1.5 title 'u%s(x)'", file, 3 * i + 3 + 2, small);
			else
				fprintf(gnuplot, "plot '%s' u 1:%d w l lw 1.5 title 'u%s(x)'", file, 3 * i + 3 + 2, small);
			started = true;
			free(small);
		}
	}
	if (options & 0b00010000)
	{
		for (int i = 0 ; i < nf ; i++)
		{
			small = small_text(i + 1);
			if (started)
				fprintf(gnuplot, ", '%s' u 1:%d w l lw 1.5 title 'a%s*u%s(x)'", file, 3 * i + 3 + 3, small, small);
			else
				fprintf(gnuplot, "plot '%s' u 1:%d w l lw 1.5 title 'a%s*u%s(x)'", file, 3 * i + 3 + 3, small, small);
			started = true;
			free(small);
		}
	}
	fprintf(gnuplot, "\n");
	fflush(gnuplot);
	_pclose(gnuplot);
	free(p);
	return (0);
}





static void	print_usage(void)
{
	printf("Modo de uso:\n");
	printf("\t$>make plot OPT=<itens>\n");
	printf("\t$>./graph <itens>\n\n");
	printf("Itens:\n");
	printf("\t1 : distribuicao de calor final fornecida - u_T\n");
	printf("\t2 : distribuicao de calor final calculada - u_Tk\n");
	printf("\t3 : intensidade das fontes - a_k\n");
	printf("\t4 : distribuicao de calor das fontes - u_k\n");
	printf("\t5 : distribuicao de calor das fontes com intensidade - a_k*u_k\n\n");
	printf("Exemplo\n");
	printf("\t$> ./graph 15\n");
	printf("\t[Este comando ira plotar o grafico de 1 e 5]\n");
}

static char process_options(char *argv)
{
	int		i;
	char	options;

	i = 0;
	options = 0;
	while (i < (int)strlen(argv))
	{
		switch (argv[i])
		{
			case '1' : options |= 0b00000001; break;
			case '2' : options |= 0b00000010; break;
			case '3' : options |= 0b00000100; break;
			case '4' : options |= 0b00001000; break;
			case '5' : options |= 0b00010000; break;
			default : options |= 0b00000000;
		}
		i++;
	}
	return (options);
}

static char	*my_itoa(int num)
{
	int		i;
	int		size;
	int		last_d;
	char	aux;
	char	*result;
	

	size = 0;
	result = NULL;
	if (!num)
		return (strdup("0"));
	while (num)
	{
		last_d = num % 10;
		size++;
		result = realloc(result, (size + 1) * sizeof(char));
		result[size - 1] = '0' + last_d;
		result[size] = '\0';
		num /= 10;
	}
	i = 0;
	while (i < (int)(strlen(result) / 2))
	{
		aux = result[i];
		result[i] = result[strlen(result) - (i + 1)];
		result[strlen(result) - (i + 1)] = aux;
		i++;
	}
	return (result);
}

static char	*small_text(int	num)
{
	int		i;
	char	*mander;
	char	*result;

	mander = my_itoa(num);
	result = (char*)malloc((2 * strlen(mander) + 1) * sizeof(char));
	i = 0;
	while (i < (int)(2 * strlen(mander)))
	{
		result[i] = (i % 2) ? mander[i / 2] : '_';
		i++;
	}
	result[i] = '\0';
	free(mander);
	return (result);
}
