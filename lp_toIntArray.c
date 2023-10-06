#include "murmurlibc.h"

static void    assign(void *node, int index, void *data)
{
    ((int *)data)[index] = (int)(size_t)(((t_link)node)[0]);
}

int *lp_toIntArray(t_link lp)
{
    int *arr;

    arr = callocate(sizeof(int), lp_len(lp));
    lp_iter(lp, 0, assign, arr);
    return (arr);
}