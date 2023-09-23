#include "murmurlibc.h"

t_link	lp_filter(t_link nod, int f(void *node_iterate, void *data_compare), void *data)
{
	while (nod)
	{
        if (f(nod, data))
            return (nod);
		nod = nod[1];
	}
	return (NULL);
}

// int f(void *pa1, void *pa2)
// {
//     if ((int)((t_link)(((t_link)pa1)[1]))[0] == (int)pa2)
//         return (1);
//     else
//         return (0);
// }

// int	main(int ac, char *av[])
// {
// 	int		i;
// 	t_link	genesis;
// 	t_link	tmp;

// 	genesis = NULL;
// 	i = 3131;
// 	while (i <= 3231)
// 	{
// 		tmp = lp_new((void *)(long)i);
// 		lp_push(&genesis, tmp);
// 		i++;
// 	}
// 	i = 0;
// 	while (i <= 100)
// 	{
// 		p("val: %d, ", lp_nod(genesis, i)[0]);
// 		if (((t_link)(lp_nod(genesis, i)[1])))
// 			p("next-val: %d, ", (int)((t_link)(lp_nod(genesis, i)[1]))[0]);
// 		else
// 			p("next-val: %d, ", 0);
// 		if (((t_link)(lp_nod(genesis, i)[2])))
// 			p("prev-val: %d\n", (int)((t_link)(lp_nod(genesis, i)[2]))[0]);
// 		else
// 			p("prev-val: %d\n", 0);
// 		i++;
// 	}
//     t_link a;
//     a = lp_filter(genesis, f, (void *)3149);
//     if (a)
//         p("%d\n", a[0]);
// 	return (0);
// }