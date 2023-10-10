/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:56:24 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/10 16:09:04 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags *flags)
{
	int	extra;

	extra = flags->width - 1;
	if (flags->width != -1 && !flags->dash && extra > 0)
		while (extra--)
			write(1, " ", 1);
	write(1, &c, 1);
	if (extra > 0 && flags->dash)
		while (extra--)
			write(1, " ", 1);
	return (ft_max(1, flags->width));
}
