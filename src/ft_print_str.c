#include "../include/ft_printf.h"

int	ft_print_str(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		ft_print_char(s[i++]);
	}
	return (i);
}
