#include "murmurlibc.h"

void	freedom(void **adr)
{
	free(*adr);
	*adr = 0;
}
