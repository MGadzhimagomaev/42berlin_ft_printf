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

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i+1] == 'c')
			{
				counter += ft_print_char(va_arg(args, int));
				i++;
			}
			else if (str[i+1] == 's')
			{
				counter += ft_print_str(va_arg(args, char *));
				i++;
			}
			else if (str[i+1] == 'i' || str[i+1] == 'd')
			{
				counter += ft_print_num(va_arg(args, int));
				i++;
			}
			else if (str[i+1] == '%')
				ft_print_char(str[++i]);
			else
			{
				ft_print_char(str[i]);
				counter++;
			}
		}
		else
		{
			ft_print_char(str[i]);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			ft_printf(argv[i]);
			ft_print_char(' ');
			i++;
		}
	ft_print_char('\n');
	}
	ft_printf("Try to print this:\nchar: %c\nstr: %s\nint: %d\npercent: %%\n", 'i', "this", 5);
}