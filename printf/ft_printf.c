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
gcc ft_printf.c /Users/hugofds/desktop/{42}/printf/include/libft/libft.a && ./a.out

gcc ft_aux.c /Users/hugofds/desktop/{42}/printf/include/libft/libft.a && ./a.out

*/
//function finds the next occurence of % and returns NULL if there are no more in the string.
//will also check if its the first time checking or not.
/*
char	*get_next_percent(const char *flag_string, int	iterations)
{
	char	*next_percent;

	if (iterations == 0)
		next_percent = ft_strchr(flag_string, '%');
	else
		next_percent = ft_strchr(flag_string + 1, '%');
	if (next_percent == 0)
		return NULL ;
	return (next_percent);

}
*/
//mothership function, Initializes va_arg list as well as assigning the flag value to pass onto the sorting machine above.
//the while loop iterates through the string untill a null character is found or untill there are no more flags.
int		ft_printf(const char *flag_string, ...)
{
	va_list	args;
//	char	flag;
//	char	*next_percent;
//	int		iterations;

//	iterations = 0;
	va_start(args, flag_string);
	while (*flag_string)
	{
		if (*flag_string == '%')
		{
//		next_percent = get_next_percent(flag_string, iterations);
//		if (next_percent == NULL)
//			break ;
//		flag = *(next_percent + 1);
			flag_string++;
			if (*flag_string == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			if (*flag_string == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			if (*flag_string == 'd' || *flag_string == 'i')
				ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
			if (*flag_string == 'u')
				ft_putstr_fd(itou(va_arg(args, unsigned int)), 1);
			if (*flag_string == '%')
				ft_putchar_fd('%', 1);
			if (*flag_string == 'X')
				ft_putstr_fd(itohex(va_arg(args, int)), 1);
			if (*flag_string == 'x')
				ft_putstr_fd(sitohex(va_arg(args, int)), 1);
			if (*flag_string == 'p')
				ft_putstr_fd(print_ptr(va_arg(args, void *)), 1);
			flag_string++;
		}
		else
		{
			ft_putchar_fd(*flag_string, 1);
			flag_string++;
		}
//		flag_string = next_percent;
//		iterations++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
//	int	test;
//	int	*ptr;

//	test = 15;
//	ptr = &test;
	ft_printf("my printf: %c %s %d$", 'x', "dude", 33);
//	ft_printf("my printf: %c %s %d %i %u %% %X %x %p$", 'x', "test", 42, 420, 1000, 500, 500, ptr);
	write(1, "\n", 1);
//	printf("printf: %c %s %d %i %u %% %X %x %p$", 'x', "test", 42, 420, 1000, 500, 500, ptr);

	return (0);
}
