/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:23:29 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/08 20:33:13 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_print_num(int n)
{
	char	*num;
	int		counter;

	num = ft_itoa(n);
	if (!num)
		return (-1);
	counter = ft_print_str(num);
	free(num);
	if (counter == -1)
		return (-1);
	return (counter);
}
