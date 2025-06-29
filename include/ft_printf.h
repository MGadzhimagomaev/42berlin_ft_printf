/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:23:44 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/08 20:07:38 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(const char c);
int	ft_print_str(const char *s);
int	ft_print_num(int n);
int	ft_print_unsigned_int(unsigned int n);
int	ft_print_hex(unsigned int n, char c);
int	ft_print_ptr(void *p);

#endif