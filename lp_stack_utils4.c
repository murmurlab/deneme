#include "murmurlibc.h"

int	midlen(int val, int len)
{
	if (val > len / 2 && len > 1)
		return (len - val);
	else
		return (val);
}

int	find_index_of_smallest(t_link stack)
{
	int	ret;
	int	small;
	int	ct;

	small = (int)stack[0];
	ret = 0;
	ct = 0;
	while (stack)
	{
		if (small > (int)stack[0])
		{
			small = (int)stack[0];
			ret = ct;
		}
		stack = stack[1];
		ct++;
	}
	return (ret);
}