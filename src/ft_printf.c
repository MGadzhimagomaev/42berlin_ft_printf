/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:00:25 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/03 20:15:30 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_format(const char c, va_list *args)
{
	int		counter;

	counter = 0;
	if (c == 'c')
		counter = ft_print_char(va_arg(*args, int));
	else if (c == 's')
		counter = ft_print_str(va_arg(*args, char *));
	else if (c == 'i' || c == 'd')
		counter = ft_print_num(va_arg(*args, int));
	else if (c == 'u')
		counter = ft_print_unsigned_int(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		counter = ft_print_hex(va_arg(*args, unsigned int), c);
	else if (c == 'p')
		counter = ft_print_ptr(va_arg(*args, void *));
	else if (c == '%')
		counter = ft_print_char(c);
	if (counter == -1)
		return (-1);
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		i;
	int		len;

	counter = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		len = 0;
		if (str[i] == '%' && str[i + 1])
		{
			len += ft_format(str[i + 1], &args);
			i++;
		}
		else
			len += ft_print_char(str[i]);
		if (len == -1)
			return (-1);
		counter += len;
		i++;
	}
	va_end(args);
	return (counter);
}
/*
int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int*	p;

	j = 1002;
	p = &j;
	i = 0;
	while (argc-- > 1)
	{
		ft_printf(argv[i++]);
		ft_print_char(' ');
		argc--;
	}
	ft_print_char('\n');
	ft_printf("Try to print this:\nchar: %c\nstr: %s\nint: %d\n
	int: %u\nhex: %x\nHEX: %X\npointer: %p\npercent: %%\n", 'i',
	"this", 5, 4294967295, 1002, 7953425, *p);
}*/