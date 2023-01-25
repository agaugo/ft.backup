/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <hflohil-@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:12:58 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:17:13 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//headerfile for printf.
#include "ft_printf.h"
#include "ft_printf_utils.c"

/*
Laptop:
gcc ft_printf.c /Users/hugofds/desktop/{42}/printf/include/libft/libft.a && ./a.out

42:
gcc ft_printf.c /Users/hugofds/desktop/{42}/printf/include/libft/libft.a && ./a.out

*/

int		ft_printf(const char *flag_string, ...)
{
	int		count;
	void	*result;
	char	*s_result;
	va_list	args;

	count = 0;
	result = NULL;
	va_start(args, flag_string);
	while (*flag_string)
	{
		if (*flag_string == '%')
		{
			flag_string++;
			if (*flag_string == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			if (*flag_string == 's')
			{
				s_result = va_arg(args, char *);
				if (s_result)
				{
					ft_putstr_fd(s_result, 1);
					count += count_chars(s_result) - 1;
				}
			}
			if (*flag_string == 'd' || *flag_string == 'i')
				result = ft_itoa(va_arg(args, int));
			if (*flag_string == 'u')
				result = itou(va_arg(args, unsigned int));
			if (*flag_string == '%')
				ft_putchar_fd('%', 1);
			if (*flag_string == 'X')
				result = itohex(va_arg(args, int));
			if (*flag_string == 'x')
				result = sitohex(va_arg(args, int));
			if (*flag_string == 'p')
				result = print_ptr(va_arg(args, void *));
			if (result)
			{
				ft_putstr_fd(result, 1);
				free(result);
			}
			result = NULL;
			flag_string++;
		}
		else
		{
			ft_putchar_fd(*flag_string, 1);
			flag_string++;
		}
		count++;
	}
	va_end(args);
	return (count);
}

/*
int	main(void)
{
//	int	test;
//	int	*ptr;

//	test = 15;
//	ptr = &test;
	ft_printf("my printf: c: %c s: %s i: %i d: %d    ", 'x', "dude", 10, 10);
//	ft_printf("my printf: %c %s %d %i %u %% %X %x %p$", 'x', "test", 42, 420, 1000, 500, 500, ptr);
	write(1, "\n", 1);
//	printf("printf: %c %s %d %i %u %% %X %x %p$", 'x', "test", 42, 420, 1000, 500, 500, ptr);

	return (0);
}
*/

