#include "ft_printf.h"

int	ft_print_str(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_print_char(s[i++]);
	}
	return (i);
}