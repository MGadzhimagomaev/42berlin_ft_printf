#include "../include/ft_printf.h"
#include "../include/libft.h"

static unsigned int	digit_count(unsigned int n)
{
	unsigned int	result;

	result = 1;
	while (n >= 10)
	{
		n /= 10;
		result++;
	}
	return (result);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*output;
	size_t	len;

	len = digit_count(n);
	output = (char *)ft_calloc(len + 1, sizeof(char));
	if (!output)
		return (NULL);
	output[len] = '\0';
	while (n >= 10)
	{
		output[--len] = (n % 10) + '0';
		n /= 10;
	}
	output[len - 1] = n + '0';
	return (output);
}

int	ft_print_unsigned_int(unsigned int n)
{
	char			*num;
	unsigned int	counter;

	num = ft_uitoa(n);
	counter = ft_print_str(num);
	free(num);
	return (counter);
}
