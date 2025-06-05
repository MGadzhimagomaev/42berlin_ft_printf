#include "ft_printf.h"

int	ft_print_char(const char c)
{
	write(1, &c, 1);
	return (1);
}