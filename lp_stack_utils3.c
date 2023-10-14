#include "murmurlibc.h"

int	find_2nd_biggest(t_link stack)
{
	int	ret;
	int	ret2;

	ret = (int)stack[0];
	ret2 = (int)stack[0];
	while (stack)
	{
		if ((int)stack[0] > ret)
		{
			ret2 = ret;
			ret = (int)stack[0];
		}
		if ((int)stack[0] < ret && (int)stack[0] > ret2)
			ret2 = (int)stack[0];
		stack = stack[1];
	}
	return (ret2);
}

int	get_closest(t_link stack, int pivot, int mod)
{
	int	ct2;
	int	ct;
	int	len;

	len = lp_len(stack);
	ct = 0;
	ct2 = 0;
	while (stack)
	{
		if (mod)
		{
			if (pivot > (int)stack[0])
			{
				ct2 = 1;
				break ;
			}
		}
		else
		{
			if (pivot <= (int)stack[0])
			{
				ct2 = 1;
				break ;
			}
		}
		stack = stack[1];
		ct++;
	}
	if (!ct2)
		return (-1);
	stack = lp_end(stack);
	ct2 = len;
	while (stack)
	{
		if (mod)
		{
			if (pivot > (int)stack[0])
				break ;
		}
		else
		{
			if (pivot <= (int)stack[0])
				break ;
		}
		stack = stack[2];
		ct2++;
	}
	if (ct < (ct2 % len))
		return (ct);
	else
		return (ct2);
	return (-1);
}

int	find_biggest(t_link stack)
{
	int	ret;
	int	ct;

	ret = 0;
	ct = 0;
	while (stack)
	{
		if ((int)stack[0] > ret)
			ret = (int)stack[0];
		stack = stack[1];
		ct++;
	}
	return (ret);
}

int	find_index_of_biggest(t_link stack)
{
	int	ret;
	int	ct;

	ret = 0;
	ct = 0;
	while (stack)
	{
		if ((int)stack[0] > ret)
			ret = ct;
		stack = stack[1];
		ct++;
	}
	return (ret);
}

int	between(t_link stack, int val)
{
	int	ct;
	int	next;
	int	prev;
	int	smallest;
	int	biggest;

	ct = 0;
	biggest = find_biggest(stack);
	smallest = find_smallest(stack);
	if (val < smallest)
		smallest = val;
	while (lp_nod(stack, ct))
	{
		if (lp_nod(stack, ct - 1))
			prev = (int)(size_t)(lp_nod(stack, ct - 1)[0]);
		else
			(prev = (int)(lp_end(stack)[0]));
		if (lp_nod(stack, ct))
			next = (int)(size_t)(lp_nod(stack, ct)[0]);
		else
			(next = (int)(stack[0]));
		if ((prev < val && next > val) || (prev == biggest && val == smallest \
		) || (prev < val && next == smallest))
			return (ct);
		ct++;
	}
	return (ct);
}
