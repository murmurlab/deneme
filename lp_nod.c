#include "murmurlibc.h"

t_link	lp_nod(t_link node, int index)
{
	if (index < 0)
		return (0);
	while (index-- > 0 && node[1])
		node = node[1];
	if (index)
		return (0);
	return (node);
}
