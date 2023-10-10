/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:57:07 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/10 17:01:16 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putstr(char *str, t_flags *flags)
{
	int	length;
	int	extra;

	extra = 0;
	length = ft_strlen(str);
	if (!str && (flags->dot >= 6 || flags->dot == -1))
		length = 6;
	if (flags->dot != -1 && length > flags->dot)
		length = flags->dot;
	if (flags->width != -1)
		extra = flags->width - length;
	if (extra > 0 && !flags->dash)
		while (extra--)
			write(1, " ", 1);
	if (length > 0 && str)
		write(1, str, length);
	else if (length == 6 && !str)
		write(1, "(null)", 6);
	if (extra > 0 && flags->dash)
		while (extra--)
			write(1, " ", 1);
	return (ft_max(length, flags->width));
}
