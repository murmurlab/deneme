#include "murmurlibc.h"

t_link	lp_nod(t_link node, int index)
{
	while (index-- > 0 && node[1])
		node = node[1];
	return (node);
}
