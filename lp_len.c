// ahbasara

#include "murmurlibc.h"

int	lp_len(t_link lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst[1];
		i++;
	}
	return (i);
}

/* {
	size_t		i;

	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
} */
