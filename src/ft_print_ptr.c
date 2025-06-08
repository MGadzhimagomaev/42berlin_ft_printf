#include "../include/ft_printf.h"
#include "../include/libft.h"

static int	ft_print_hex_ptr(unsigned long n)
{
	char	*base;
	int		count;
	int		len;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		len = ft_print_hex_ptr(n / 16);
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

int	ft_print_ptr(void *p)
{
	int		count;
	int		len;
	unsigned long	n;

	n = (unsigned long)p;
	count = ft_print_str("0x");
	if (count == -1)
		return (-1);
	len = ft_print_hex_ptr(n);
	if (len == -1)
		return (-1);
	count += len;
	return (count);
}