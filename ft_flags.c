/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 18:28:57 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/31 18:29:37 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			flags->space = 1;
		else if (format[index] == '+')
			flags->plus = 1;
		else if (format[index] == '#')
			flags->hashtag = 1;
		else if (format[index] == '-')
			flags->dash = 1;
		else if (format[index] == '0')
			flags->zero = 1;
		++index;
	}
	if (format[index] >= '0' && format[index] <= '9')
		index += set_flag_value(format, index, &flags->width);
	if (format[index] == '.')
		index += (set_flag_value(format, index + 1, &flags->dot) + 1);
	return (index);
}

void	ft_print_flags(t_flags *flags, int *count)
{
	*count += write(1, "%", 1);
	if (flags->hashtag)
		*count += write(1, "#", 1);
	if (flags->space && !flags->plus)
		*count += write(1, " ", 1);
	else if (flags->plus)
		*count += write(1, "+", 1);
	if (flags->zero && !flags->dash)
		*count += write(1, "0", 1);
	else if (flags->dash)
		*count += write(1, "-", 1);
	if (flags->width != -1)
		*count += ft_put_uint(flags->width, 1);
	if (flags->dot != -1)
	{
		*count += write(1, ".", 1);
		*count += ft_put_uint(flags->dot, 1);
	}
}
