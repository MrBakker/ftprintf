/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 13:52:13 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/31 19:26:29 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	hashtag;
	int	space;
	int	plus;
	int	dash;
	int	zero;
	int	dot;
	int	width;
}	t_flags;

int		ft_abs(int num);
int		ft_max(int a, int b);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c, t_flags *flags);
int		ft_putnum(int num, t_flags *flags);
int		ft_putunum(int num, t_flags *flags);
int		ft_putstr(char *str, t_flags *flags);
int		ft_putvoidptr(void *ptr, t_flags *flags);
int		ft_put_uint(unsigned int numb, int print);
int		ft_printhex(int num, int hex, t_flags *flags);
int		get_flags(const char *format, int index, t_flags *flags);
int		set_flag_value(const char *format, int index, int *flag);

char	num_to_hex(int num, char base_case);

void	ft_bzero(void *s, size_t n);
void	ft_print_flags(t_flags *flags, int *count);

void	*ft_memcpy(void *dest, const void *src, size_t n);

size_t	ft_strlen(const char *s);

#endif