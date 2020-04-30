#include "ep1.h"

static void	free_matrix(double ***m, int pos);

bool		create_matrix(double ***m, int rows, int cols)
{
	int	i;

	i = 0;
	if (!(*m = (double**)malloc(rows * sizeof(double*))))
		return (false);
	while (i < rows)
	{
		if (!((*m)[i] = (double*)malloc(cols * sizeof(double))))
		{
			free_matrix(m, i - 1);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	free_matrix(double ***m, int pos)
{
	while (pos >= 0)
	{
		free((*m)[pos]);
		pos--;
	}
	free(*m);
}
