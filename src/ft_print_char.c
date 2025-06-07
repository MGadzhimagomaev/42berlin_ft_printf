#include "../include/ft_printf.h"

int	ft_print_char(const char c)
{
	return(write(1, &c, 1));
}
