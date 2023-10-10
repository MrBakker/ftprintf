/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:58:19 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/10 16:57:19 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length])
		++length;
	return (length);
}

char	num_to_hex(int num, char base_case)
{
	return ((num < 10) * '0' + (num > 9) * (base_case - 10) + num);
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
		*ptr++ = '\0';
}

int	ft_max(int a, int b)
{
	return ((a > b) * a + (b >= a) * b);
}
