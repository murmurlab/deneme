#include "murmurlibc.h"

void	**lpnod(void **node, int index)
{
	while (index-- > 0 && node[1])
		node = node[1];
	return (node);
}
