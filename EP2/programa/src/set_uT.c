#include "../inc/ep2.h"

/*
** Function that sets u_T values
*/

static double	set_noise(double x);
static bool		read_u_file(heat *u, data *info);

bool			set_uT(heat *u, data *info)
{
	int		i;

	u->u_T = (double*)malloc((info->N + 1) * sizeof(double));
	if (info->ex == 'a')
	{
		i = 0;
		while (i <= info->N)
		{
			u->u_T[i] = 7.0 * u->u_k[0][i];
			i++;
		}
	}
	else if (info->ex == 'b')
	{
		i = 0;
		while (i <= info->N)
		{
			u->u_T[i] = (2.3 * u->u_k[0][i])
						+ (3.7 * u->u_k[1][i])
						+ (0.3 * u->u_k[2][i])
						+ (4.2 * u->u_k[3][i]);
			i++;
		}
	}
	else
		read_u_file(u, info);
	return (true);
}





static double	set_noise(double x)
{
	double	r;
	double	e;
	double	noisy;

	srand(time(0));
	e = 0.01;
	r = ((2.0 / (double)RAND_MAX) * rand()) - 1.0;
	//noisy = x + (r * e);
	noisy = x * (1.0 + (r * e));
	return (noisy);
}

static bool		read_u_file(heat *u, data *info)
{
	int		fd;
	int		i;
	int		k;
	char	*line;

	fd = open(NAME_FILE, O_RDONLY);
	get_next_line(fd, &line);
	free(line);
	get_next_line(fd, &line);
	free(line);
	i = 0;
	k = 0;
	while (i <= N_FILE)
	{
		if (get_next_line(fd, &line) > 0 && !(i % (N_FILE / info->N)))
		{
			u->u_T[k] = (info->ex == 'd') ? set_noise(atof(line)) : atof(line);
			k++;
		}
		free(line);
		i++;
	}
	close(fd);
	return (true);
}
