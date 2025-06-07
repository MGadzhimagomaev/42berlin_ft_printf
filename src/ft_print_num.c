#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_print_num(int n)
{
	char	*num;
	int		counter;

	num = ft_itoa(n);
	counter = ft_print_str(num);
	free(num);
	return (counter);
}

