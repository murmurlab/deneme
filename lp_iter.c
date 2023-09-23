// ahbasara

#include "murmurlibc.h"

int	lp_iter(t_link lst, int iteration_number,void (*f)(void *iterated, int index, void *data_passed), void *pass_data)
{
    int i;

    i = 0;
	if (!f)
		return (0);
	while ((iteration_number == 0 || iteration_number-- > 1) && lst)
	{
		(*f)(lst, i, pass_data);
		lst = lst[1];
        i++;
	}
    return (i);
}
