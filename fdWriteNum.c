// ahbasara

#include "murmurlib.h"
/* 
void	ft_putnbr_fd(int n, int fd)
{
	char	*s;
	
	s = malloc(ft_strlen(ft_itoa(n)));
	ft_memcpy(s, ft_itoa(n), ft_strlen(ft_itoa(n)));
	write(fd, s, ft_strlen(ft_itoa(n)));
}
 */

void	fdWriteNum(int n, int fd)
{
	if (n == -2147483648)
		fdWriteStr("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			fdWriteChar('-', fd);
			n = n * -1;
		}
		if (n >= 9)
		{
			fdWriteNum(n / 10, fd);
		}
		fdWriteChar((n % 10) + '0', fd);
	}
}

/* 
int	main(void)
{
    ft_putnbr_fd(5,1);
}
 */