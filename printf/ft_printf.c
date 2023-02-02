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

//header file for printf.
#include "ft_printf.h"
#include "ft_printf_utils.c"

/*
Laptop:
gcc ft_printf.c /Users/hugofds/desktop/{42}/printf/include/libft/libft.a && ./a.out

42:
gcc ft_printf.c /Users/hflohil-/Desktop/github42ls/printf/libft/libft.a && ./a.out

*/

int		ft_printf(const char *flag_string, ...)
{
	int		count;
	int		var;
	void	*buffer;
	char	*arg;
	va_list	args;

	count = 0;
	va_start(args, flag_string);
	while (*flag_string)
	{
		if (*flag_string == '%')
		{
			flag_string++;
			if (*flag_string == 'c')
			{
				var = va_arg(args, int);
				ft_putchar_fd(var, 1);
			}
			if (*flag_string == '%')
				ft_putchar_fd('%', 1);
			if (*flag_string == 'd' || *flag_string == 'i')
				buffer = ft_itoa(va_arg(args, int));
			if (*flag_string == 'u')
				buffer = itou(va_arg(args, unsigned int));
			if (*flag_string == 'X')
				buffer = itohex(va_arg(args, uintptr_t));
			if (*flag_string == 'x')
				buffer = sitohex(va_arg(args, uintptr_t), 0);
			if (*flag_string == 'p')
			{
				buffer = sitohex(va_arg(args, uintptr_t), 1);
				count += 2;
			}
			if (*flag_string == 's')
			{
				arg = va_arg(args, char *);
				if (arg == NULL)
				{
					ft_putstr_fd("(null)", 1);
					count += 5;
					buffer = NULL;

				}	
				else
					buffer = ft_strdup(arg);
			}
			if (buffer)
			{
				ft_putstr_fd(buffer, 1);
				count += ft_strlen(buffer) - 1;
				free(buffer);
			}
		}
		else
			ft_putchar_fd(*flag_string, 1);
		count++;
		flag_string++;
	}
	va_end(args);
	return (count);
}

/*
int	main(void)
{
	long int	LONG_MIN;
	long int	LONG_MAX;

	LONG_MIN = -9223372036854775808;
	LONG_MAX = 9223372036854775807;
	ft_printf("$%p$", LONG_MIN, LONG_MAX);
	write(1, "\n", 2);
	printf("$%p$", LONG_MIN, LONG_MAX);
	return (0);
}
*/