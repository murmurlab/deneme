// ahbasara

#include "murmurlibc.h"

void	lp_push(t_link *bash, t_link new)
{
	if (bash)
	{
		if (*bash)
		{
			new[1] = *bash;
			(*bash)[2] = new;
		}
		*bash = new;
	}
}
