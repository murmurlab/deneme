// ahbasara

#include "murmurlibc.h"

t_link  lp_end(t_link lst)
{
	while (lst)
	{
		if (!lst[1])
			return (lst);
		lst = lst[1];
	}
	return (lst);
}

/* {
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
} */
