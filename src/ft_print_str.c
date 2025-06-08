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
		if (ft_print_char(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

/*
int main()
{
	ft_print_str("string\n");
//	ft_print_str(" %c %c %c \n", '1', '2', '3');
//	ft_print_str(" %c %c %c \n", '2', '1', 0);
}*/