#include "murmurlibc.h"

static void assign(void *node, int index, void *data)
{
    t_link  tmp;

    (void)index;
    tmp = lp_new(((t_link)node)[0]);
    lp_add((t_link *)data , tmp);
}

t_link  lp_dup(t_link lp)
{
    t_link  new_lp;

    new_lp = NULL;
    lp_iter(lp, 0, assign, &new_lp);
    return (new_lp);
}