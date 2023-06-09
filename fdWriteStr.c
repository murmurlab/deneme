// ahbasara

#include "murmurlibc.h"

void	fdWriteStr(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, xstrlen(s));
}
/* 
int	main(void)
{
	ft_putstr_fd("aaaaa", 0);
}
 */