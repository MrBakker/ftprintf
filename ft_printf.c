/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 13:52:08 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/10 16:09:26 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	set_flag_value(const char *format, int index, int *flag)
{
	int	output;
	int	count;

	output = 0;
	count = 0;
	while (format[index] >= '0' && format[index] <= '9')
	{
		output = output * 10 + format[index] - '0';
		index++;
		count++;
	}
	*flag = output;
	return (count);
}

int	get_flags(const char *format, int index, t_flags *flags)
{
	ft_bzero(flags, sizeof(t_flags));
	flags->width = -1;
	flags->dot = -1;
	while (format[index] == ' ' || format[index] == '+' || format[index] == '#'
		|| format[index] == '-' || format[index] == '0')
	{
		if (format[index] == ' ')
			flags->space++;
		else if (format[index] == '+')
			flags->plus++;
		else if (format[index] == '#')
			flags->hashtag++;
		else if (format[index] == '-')
			flags->dash++;
		else if (format[index] == '0')
			flags->zero++;
		++index;
	}
	if (format[index] >= '0' && format[index] <= '9')
		index += set_flag_value(format, index, &flags->width);
	if (format[index] == '.')
		if (format[++index] >= '0' && format[index] <= '9')
			index += (set_flag_value(format, index, &flags->dot));
	return (index);
}

int	function_switch(char c, va_list *arguments, t_flags *flags)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*arguments, int), flags));
	if (c == 's')
		return (ft_putstr(va_arg(*arguments, char *), flags));
	if (c == 'p')
		return (ft_putvoidptr(va_arg(*arguments, void *), flags));
	if (c == 'd' || c == 'i')
		return (ft_putnum(va_arg(*arguments, int), flags));
	if (c == 'u')
		return (ft_putunum(va_arg(*arguments, unsigned int), flags));
	if (c == 'x')
		return (ft_printhex(va_arg(*arguments, int), 'a', flags));
	if (c == 'X')
		return (ft_printhex(va_arg(*arguments, int), 'A', flags));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_flags	flags;
	va_list	arguments;
	int		index;
	int		word_counter;

	index = 0;
	word_counter = 0;
	va_start(arguments, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			index = get_flags(format, index + 1, &flags);
			word_counter += function_switch(format[index], &arguments, &flags);
		}
		else
		{
			word_counter++;
			write(1, &format[index], 1);
		}
		++index;
	}
	va_end(arguments);
	return (word_counter);
}
