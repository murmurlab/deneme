#include "murmurlibc.h"

void	lp_pop(t_link *adrofnod, void (*del)(void **))
{
	t_link	tmp;

	if (!del || !adrofnod || !*adrofnod)
		return ;
	if (adrofnod && *adrofnod)
	{
		tmp = (*adrofnod)[1];
		lp_del(*adrofnod, del);
		(*adrofnod)[2] = 0; 
		*adrofnod = tmp;
	}
}
