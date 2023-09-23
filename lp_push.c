
// ahbasara

#include "murmurlibc.h"

void	lp_push(t_link *bash, t_link new)
{
	if (bash)
	{
		if (*bash)
		{
			new[1] = *bash;
			(*bash)[2] = new;
		}
		*bash = new;
	}
}

/*
int	main(void)
{
	t_list	*list;
	char	*str = "Hello";

	list = ft_lstnew(str);
	printf("1st: %s\n", (char *)list->content);
	ft_lstadd_front(&list, ft_lstnew("aaaa"));
	printf("1st: %s\n", (char *)list->next->content);

}
*/
