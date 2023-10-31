/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:56:24 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/31 19:50:06 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags *flags)
{
	int	extra;

	extra = flags->width - 1;
	while (extra-- > 0 && !flags->dash)
		write(1, " ", 1);
	write(1, &c, 1);
	while (extra-- >= 0)
		write(1, " ", 1);
	return (ft_max(1, flags->width));
}
