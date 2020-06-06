#include "../inc/ep2.h"

/*
** build the 'data' structure
*/

extern int	USER_N;
extern int	USER_M;

static bool	set_nf_p(data *info);

bool		process_info(heat *u, data *info)
{
	USER_N = info->N;
	USER_M = info->M;
	info->d_x = 1.0 / info->N;
	info->d_t = T / info->M;
	info->lambda = (info->d_t) / (pow(info->d_x, 2.0));
	info->f = &fonte;
    info->g1 = &fronteira_1;
    info->g2 = &fronteira_2;
	set_nf_p(info);
	u->u_k = (double**)malloc(info->nf * sizeof(double*));
	return (true);
}





static bool	set_nf_p(data *info)
{
	int		i;
	int		k;
	int		fd;
	char	*line;
	char	*num;

	if (info->ex == 'a')
	{
		info->nf = 1;
		info->p = (double*)malloc(info->nf * sizeof(double));
		info->p[0] = 0.35;
		return (true);
	}
	else if (info->ex == 'b')
	{
		info->nf = 4;
		info->p = (double*)malloc(info->nf * sizeof(double));
		info->p[0] = 0.15;
		info->p[1] = 0.3;
		info->p[2] = 0.7;
		info->p[3] = 0.8;
		return (true);
	}
	fd = open(NAME_FILE, O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	i = 0;
	info->nf = 0;
	info->p = NULL;
	while (line[i])
	{
		if (isspace(line[i]))
			i++;
		else
		{
			k = 1;
			while (!isspace(line[i + k]))
				k++;
			num = strndup(&line[i], k);
			(info->nf)++;
			info->p = (double*)realloc(info->p, info->nf * sizeof(double));
			info->p[info->nf - 1] = atof(num);
			free(num);
			i += k;
		}
	}
	free(line);
	return (true);
}
