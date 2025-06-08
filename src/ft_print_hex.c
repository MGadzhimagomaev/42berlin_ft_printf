#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_print_hex(unsigned int n, char c)
{
	char	*base;
	int		count;
	int		len;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
			len = ft_print_hex(n / 16, c);
			if (len == -1)
				return (-1);
			count += len;
	}
	len = ft_print_char(base[n % 16]);
	if (len == -1)
		return (-1);
	count += len;
	return (count);
}
