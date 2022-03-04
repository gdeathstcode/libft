#include "ft_printf.h"
//#include <stdio.h>

int	main(void)
{
	char *call = "BRITII";
	ft_printf("LOL");
	ft_printf("alutsar vladisla%c:\ncall: %s\nyear of birth: %d\nage: %u\nptr: %x\nPTR: %X\n%%\n",
		'd', 
		call,
		1994,
		27,
		call,
		call);
	return (0);
}
