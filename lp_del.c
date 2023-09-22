// ahbasara

#include "murmurlibc.h"

void	lp_del(t_link nod, void (*del)(void **))
{
	if (!del)
		return ;
	if (nod)
	{
		(*del)(&nod[0]);
		free(nod);
	}
}
