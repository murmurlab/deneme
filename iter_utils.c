#include "murmurlibc.h"

int		dup_cntl(void *nod, void *cmp)
{
	if (((t_link)nod)[0] == cmp)
		return (1);
	return (0);
}