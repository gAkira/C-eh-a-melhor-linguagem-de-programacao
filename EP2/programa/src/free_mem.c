#include "../inc/ep2.h"

/*
**	Function that free all memory allocated in main variables
*/

bool	free_mem(heat *u, data *info)
{
	int		i;

	free(info->p);
	free(u->D);
	free(u->u_T);
	free(u->a_k);
	i = 0;
	while (i < info->nf)
	{
		free(u->L[i]);
		free(u->u_k[i]);
		i++;
	}
	free(u->L);
	free(u->u_k);
	return (true);
}
