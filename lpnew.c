#include "murmurlibc.h"

void	**lpnew(void *content)
{
	void	**node;

	node = callocate(sizeof(void *), 2);
	if (node == NULL)
		return (NULL);
	*node = content;
	*(node + 1) = NULL;
	return (node);
}
