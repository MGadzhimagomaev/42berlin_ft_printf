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

int	ft_print_pointer(void *p)
{
	char	*base;
	int		count;
	int		len;
	unsigned long	n;

	n = (unsigned long)p;
	base = "0123456789abcdef";
	if (!ft_print_str("0x"))
		return (-1);
	count = 2;
	if (n >= 16)
	{
			len = ft_print_pointer(n / 16);
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