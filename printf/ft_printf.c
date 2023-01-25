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
gcc ft_printf.c /Users/hflohil-/Desktop/GITHUB/printf/libft/libft.a && ./a.out

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
			//string
			if (*flag_string == 's')
			{
				s_result = va_arg(args, char *);
				if (s_result)
				{
					ft_putstr_fd(s_result, 1);
					count += count_chars(s_result);
				}
			}

			//character
			if (*flag_string == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				count++;
			}
			//percent sign
			if (*flag_string == '%')
			{
				ft_putchar_fd('%', 1);
				count++;
			}

			//malloc:

			//decimal or integer
			if (*flag_string == 'd' || *flag_string == 'i')
				result = ft_itoa(va_arg(args, int));
			//unsigned integer
			if (*flag_string == 'u')
				result = itou(va_arg(args, unsigned int));
			//capital letter hexadecimal
			if (*flag_string == 'X')
				result = itohex(va_arg(args, int));
			//lower case hexadecimal
			if (*flag_string == 'x')
				result = sitohex(va_arg(args, int));
			//pointer argument (address)
			if (*flag_string == 'p')
				result = print_ptr(va_arg(args, void *));
			if (result)
			{
				count += count_chars(result);
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
			count++;
		}
	}
	va_end(args);
	return (count);
}


int	main(void)
{
//	int	test;
//	int	*ptr;

//	test = 15;
//	ptr = &test;
	ft_printf("my printf: x: %x X: %X", -500, -500);
//	ft_printf("my printf: %c %s %d %i %u %% %X %x %p$", 'x', "test", 42, 420, 1000, 500, 500, ptr);
	write(1, "\n", 1);
	printf("printf: x: %x x: %x", 500, -500);

	return (0);
}


