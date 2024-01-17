/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:23:51 by faboussa          #+#    #+#             */
/*   Updated: 2023/11/28 18:22:57 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static size_t	check_format(const char c, va_list args)
{
	int	output;

	output = 0;
	if (c == '\0')
		return (-1);
	if (c == '%')
		output = ft_putchar('%');
	if (c == 'c')
		output = ft_putchar(va_arg(args, int));
	else if (c == 'i' || c == 'd')
		output = ft_print_and_count_int(va_arg(args, int), "0123456789");
	else if (c == 'p')
		output = ft_print_and_count_unsigned_long(va_arg(args, unsigned long),
				"0123456789abcdef");
	else if (c == 's')
		output = ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		output = ft_print_and_count_unsigned_int(va_arg(args, unsigned int),
				"0123456789");
	else if (c == 'x')
		output = ft_print_and_count_unsigned_int((va_arg(args, unsigned int)),
				"0123456789abcdef");
	else if (c == 'X')
		output = ft_print_and_count_unsigned_int((va_arg(args, unsigned int)),
				"0123456789ABCDEF");
	return (output);
}

int	ft_printf(const char *s, ...)
{
	int		output;
	int 	tmp;
	va_list	args;

	output = 0;
	tmp = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		tmp = output;	 
		if (*s == '%')
			output += check_format(*(++s), args);
		else
			output += ft_putchar(*s);
		if (output < tmp)
			return (-1);
		if (*s != '\0')
			s++;
	}
	return (va_end(args), output);
}
