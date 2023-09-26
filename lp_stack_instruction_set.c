#include "murmurlibc.h"

int s(t_link *stack, int a, int b)
{
	t_link  tmp;

    if (lp_len(*stack) <= 1)
        return (1);
	tmp = lp_nod(*stack, b);
	lp_swap(lp_nod(*stack, a), lp_nod(*stack, b));
	*stack = tmp;
    return (0);
}

void    d(void **v)
{
    (void)(v);
}

int m(t_link *stack_a, t_link *stack_b)
{
    void    *data;

    if (lp_len(*stack_b) < 1)
        return (1);
    data = (*stack_b)[0];
    lp_pop(stack_b, d);
    lp_push(stack_a, lp_new(data));
    return (0);
}

int mv(t_link *stack)
{
	t_link  tmp;
	t_link  tmp2;

    if (lp_len(*stack) <= 1)
        return (1);
	tmp = lp_nod(*stack, 1);
	tmp2 = lp_nod(*stack, 0);
    lp_add(stack, (*stack));
    tmp2[1] = 0;
    tmp[2] = 0;
	*stack = tmp;
    return (0);
}

int rmv(t_link *stack)
{
	t_link  tmp;

    if (lp_len(*stack) <= 1)
        return (1);
    lp_push(stack, lp_new(lp_end(*stack)[0]));
    tmp = ((t_link)(lp_end(*stack)[2]));
    lp_del(lp_end(*stack), d);
    tmp[1] = 0;
    return (0);
}

int cmd(t_link *stack_a, t_link *stack_b, char *cmd)
{
    int ret;

    if (!strncmp(cmd, "sa", 2))
        ret = (write(1, "sa\n", 3), s(stack_a, 0, 1));
    if (!strncmp(cmd, "sb", 2))
        ret = (write(1, "sb\n", 3), s(stack_b, 0, 1));
    if (!strncmp(cmd, "ss", 2))
        ret = (write(1, "ss\n", 3), s(stack_b, 0, 1) || s(stack_a, 0, 1));
    if (!strncmp(cmd, "pa", 2))
        ret = (write(1, "pa\n", 3), m(stack_a, stack_b));
    if (!strncmp(cmd, "pb", 2))
        ret = (write(1, "pb\n", 3), m(stack_b, stack_a));
    if (!strncmp(cmd, "ra", 2))
        ret = (write(1, "ra\n", 3), mv(stack_a));
    if (!strncmp(cmd, "rb", 2))
        ret = (write(1, "rb\n", 3), mv(stack_b));
    if (!strncmp(cmd, "rrr", 3))
        ret = (write(1, "rrr\n", 4), rmv(stack_b) || rmv(stack_a));
    if (!strncmp(cmd, "rra", 3))
        ret = (write(1, "rra\n", 4), rmv(stack_a));
    if (!strncmp(cmd, "rrb", 3))
        ret = (write(1, "rrb\n", 4), rmv(stack_b));
    if (!strncmp(cmd, "rr", 2))
        ret = (write(1, "rr\n", 3), mv(stack_b) || mv(stack_a));
    if (ret)
        write(1, "Error:\ncommand was not executed", 31);
    return (ret);
}


