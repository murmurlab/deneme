#include "murmurlibc.h"

int	lp_swap(t_link a, t_link b)
{
	t_link tmp;

	tmp = 0;
	if (!a || !b)
		return (0);
	if (a[1] == b)
	{
		tmp = a[2];
		a[2] = b;
		a[1] = b[1];
		b[2] = tmp;
		b[1] = a;
		if (b[2])
			((t_link)b[2])[1] = b;
		if (a[1])
			((t_link)a[1])[2] = a;
		return (1);
	}
	if (b[1] == a)
	{
		tmp = b[2];
		b[2] = a;
		b[1] = a[1];
		a[2] = tmp;
		a[1] = b;
		if (a[2])
			((t_link)a[2])[1] = a;
		if (b[1])
			((t_link)b[1])[2] = b;
		return (1);
	}
	tmp = a[1];
	a[1] = b[1];
	b[1] = tmp;
	tmp = a[2];
	a[2] = b[2];
	b[2] = tmp;
	if (a[2])
		((t_link)a[2])[1] = a;
	if (a[1])	
		((t_link)a[1])[2] = a;
	if (b[1])
		((t_link)b[1])[2] = b;
	if (b[2])
		((t_link)b[2])[1] = b;
	return (1);
}