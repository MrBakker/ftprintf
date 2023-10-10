/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:41:21 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/10 17:06:39 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	// printf("\n%d", ft_printf("String: %s + %c", "taart", '|'));
	// char *a = "a";
	// int b = ft_printf("\n%p", (void *)a);
	// printf("\n%-10c", 'a');
	// printf("b: %d c: %d", b, c);

	// float y = 435687.3242;
	// b = printf("%d", y);
	// printf("%d", b);
	// printf("\n%.100d", 0);
	// ft_printf("n|%-0c", 'c');
	// printf("o|%6.s", "Test");
	// ft_printf("o|%6.s", "Test");

	int a = -1;
	int b = ft_printf(" %.s ", "-");
	int c = printf(" %.s ", "-");
	printf("return value: %c\nb: %d | c: %d\n", ((b == c) * 'c' + (b != c) * 'w'), b, c);
	// printf("%d", printf("%s", ""));
	// if (a++ == 0 && a == 1)
		// printf("yay");

	return (0);
}
