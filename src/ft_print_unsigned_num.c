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
	while (len > 0)
	{
		output[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (output);
}

int	ft_print_unsigned_int(unsigned int n)
{
	char			*num;
	int	counter;

	num = ft_uitoa(n);
	if (!num)
		return (-1);
	counter = ft_print_str(num);
	free(num);
	if (counter == -1)
		return (-1);
	return (counter);
}
