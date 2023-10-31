/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 13:52:08 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/31 20:00:19 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

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
	return (-1);
}

void	print_normal_string(const char *ptr, int *index, int *char_count)
{
	int	length;

	length = 0;
	while (ptr[length] && ptr[length] != '%')
		length++;
	if (length)
		write(1, ptr, length);
	*index += length;
	*char_count += length;
}

void	print_argument(const char *ptr, int *idx, int *c_count, va_list *args)
{
	t_flags	flags;
	int		chars_written;
	int		chr_to_skip;

	if (ptr[0] != '%')
		return ;
	chr_to_skip = get_flags(ptr + 1, 0, &flags);
	chars_written = function_switch(*(ptr + chr_to_skip + 1), args, &flags);
	if (chars_written == -1)
	{
		ft_print_flags(&flags, &chars_written);
		*c_count += chars_written + 1;
		if (!*(ptr + chr_to_skip + 1))
			*idx -= 1;
		else if (*(ptr + chr_to_skip + 1) <= 'a'
			|| *(ptr + chr_to_skip + 1) >= 'z')
			*c_count += write(1, ptr + chr_to_skip + 1, 1);
	}
	else
		*c_count += chars_written;
	*idx += chr_to_skip + 2;
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		index;
	int		char_count;

	index = 0;
	char_count = 0;
	va_start(arguments, format);
	while (format[index])
	{
		print_normal_string(&format[index], &index, &char_count);
		print_argument(&format[index], &index, &char_count, &arguments);
	}
	va_end(arguments);
	return (char_count);
}

// char    ptr1[] = "This %s is a |%   ---+q| [% ]% ++|| test\n%000---++++
// 234563478.2345b\n\n";

// int main(void)
// {
//     char    ptr1[] = "This %s is a |%                  ++   ---0000####>\\h
//    ---+H| [%%%%%%% ]% ++|| test\n%000---++++234563478.2345Q\n\nfgggh %%%----
// 		Hoi\n%      -####]geuigh\n%----++++534534.12\n";
//     char    *ptr2 = "HELLO";

//     int count1 = printf(ptr1, ptr2);
//     int count2 = ft_printf(ptr1, ptr2);
//     if (count1 != count2)
//         {printf("\n-\nReturn value is incorrect :((\nYour function:\t%d
// \nStd function:\t%d\n-\n", count2, count1);}
// // 	char *n = NULL;
// // 	count1 = printf("%10s|\n", n);
// // 	count2 = ft_printf("%10s|\n", n);
// // 	if (count1 != count2)
// //         {printf("\n-\nReturn value is incorrect :((\nYour function:\t%d
// \nStd function:\t%d\n-\n", count2, count1);}
// // 	char format[] = "This i%2s... failed?\n";
// // 	char param[] = "s a test";
// // 	count1 = printf(format, param);
// // 	count2 = ft_printf(format, param);
// // 	if (count1 != count2)
// //         {printf("\n-\nReturn value is incorrect :((\nYour function:\t%d
// \nStd function:\t%d\n-\n", count2, count1);}
// // 	char format2[] = "This is a number %#+15.8X... failed?\n";
// // 	int payload = 1;
// // 	count1 = printf(format2, payload);
// // 	count2 = ft_printf(format2, payload);
// // 	if (count1 != count2)
// //         {printf("\n-\nReturn value is incorrect :((\nYour function:\t%d
// \nStd function:\t%d\n-\n", count2, count1);}
// }
