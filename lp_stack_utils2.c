#include "murmurlibc.h"

void iter_stack_func(void *iter, int index, void *data)
{
	(void)index;
	lp_push((t_link *)data, lp_new(((t_link)iter)[0]));
}