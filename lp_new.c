#include "murmurlibc.h"

t_link	lp_new(void *content)
{
	t_link	node;

	node = callocate(sizeof(void *), 2);
	if (node == NULL)
		return (NULL);
	*node = content;
	*(node + 1) = NULL;
	return (node);
}
