/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putvoidptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:43:41 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/23 16:11:46 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ulong(unsigned long numb, int print)
{
	char	c;
	int		out;

	out = 1;
	if (numb > 15)
		out += ft_put_ulong(numb / 16, print);
	if (print)
	{
		c = num_to_hex(numb % 16, 'a');
		write(1, &c, 1);
	}
	return (out);
}

int	ft_putvoidptr(void *ptr, t_flags *flags)
{
	int	length;
	int	extra;

	if (ptr)
		length = ft_put_ulong((unsigned long)ptr, 0) + 2;
	else
		length = 5;
	extra = flags->width - length;
	if (extra > 0 && !flags->dash)
		while (extra--)
			write(1, " ", 1);
	if (ptr)
	{
		write(1, "0x", 2);
		ft_put_ulong((unsigned long)ptr, 1);
	}
	else
		write(1, "(nil)", 5);
	if (extra > 0 && flags->dash)
		while (extra--)
			write(1, " ", 1);
	return (ft_max(flags->width, length));
}
