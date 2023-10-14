#include "murmurlibc.h"








//asarshraensharuslhdtvhsuhtdhuthslht


void	print_links(void *iter, void *data);

void	iter_stack_func(void *iter, int index, void *data)
{
	(void)index;
	lp_push((t_link *)data, lp_new(((t_link)iter)[0]));
}

int	find_smallest(t_link stack)
{
	int	ret;

	ret = (int)stack[0];
	while (stack)
	{
		if ((int)stack[0] < ret)
			ret = (int)stack[0];
		stack = stack[1];
	}
	return (ret);
}

t_link	bubble_sort(t_link stack)
{
	t_link	tmp;
	int		flag;
	t_link	bash;

	bash = stack;
	flag = 0;
	tmp = stack;
	while (1)
	{
		while (tmp)
		{
			if (!tmp[1])
				break ;
			if ((int)tmp[0] > ((int)((t_link)(tmp[1]))[0]))
			{
				if (bash == tmp)
					bash = tmp[1];
				(lp_swap(tmp, tmp[1]), flag = 1);
			}
			tmp = tmp[1];
		}
		if (!flag)
			break ;
		tmp = bash;
		flag = 0;
	}
	return (bash);
}

int	find_pivot(t_link stack)
{
	t_link	tmp_lp;
	int		ret;

	if (!stack)
		return (0);
	if (lp_len(stack) < 2)
		return (0);
	tmp_lp = lp_dup(stack);
	tmp_lp = bubble_sort(tmp_lp);
	// print_links(tmp_lp, NULL);
	ret = (int)(size_t)(lp_nod(tmp_lp, lp_len(tmp_lp) / 2)[0]);
	while (tmp_lp)
		lp_pop(&tmp_lp, del);
	return (ret);
}

int	*biggest_gap(int *zone, int *pivot, t_link stack, int len)
{
	int	*ret;
	int	tmp;
	int	target_len;
	int	stock_zone;

	stock_zone = zone[0];
	target_len = ft_fabs(((zone[1] <= zone[0]) * len) - ft_fabs(zone[1] - \
				zone[0]));
	ret = callocate(sizeof(int), 2);
	ret[0] = zone[0];
	ret[1] = -1;
	tmp = 0;
	while (target_len-- > -1)
	{
		if (((int)(size_t)(lp_nod(stack, zone[0])[0]) < pivot[0]) || zone[0] \
			==stock_zone)
		{
			if (ret[1] != -1)
			{
				if (ret[0] != -1 && ret[1] != -1 && ft_fabs(((ret[1] <= \
				ret[0]) * len) - ft_fabs(ret[1] - ret[0])) < ft_fabs(((zone[0] \
				<= tmp) * len) - ft_fabs(zone[0] - tmp)))
				{
					ret[0] = tmp;
					ret[1] = zone[0];
				}
			}
			else if (ret[0] != zone[0])
				ret[1] = zone[0];
			tmp = zone[0];
		}
		zone[0]++;
		if (zone[0] == (len))
			zone[0] = 0;
	}
	return (ret);
}