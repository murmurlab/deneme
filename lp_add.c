// ahbasara

#include "murmurlibc.h"

void	lp_add(t_link *nod, t_link new)
{
	t_link	last;

	if (nod)
	{
		if (*nod)
		{
			last = lp_end(*nod);
			new[2] = last;
			last[1] = new;
		}
		else
			*nod = new;
	}
}
