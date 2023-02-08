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

#include "ft_printf.h"

int		ft_printf(const char *flag_string, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, flag_string);
	while (*flag_string)
	{
		if (*flag_string == '%')
		{
			flag_string++;
			if (*flag_string == 'u')
				count += itou(va_arg(args, unsigned int));
			if (*flag_string == 'X')
				count += itohex(va_arg(args, unsigned int), 1);
			if (*flag_string == 'x')
				count += itohex(va_arg(args, unsigned int), 0);
			if (*flag_string == 'p')
				count += itoptr(va_arg(args, uintptr_t));
			if (*flag_string == 's')
				count += ft_str(va_arg(args, char *));
			if (*flag_string == 'd' || *flag_string == 'i')
				count += ft_int(va_arg(args, int));
			if (*flag_string == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			if (*flag_string == '%')
				ft_putchar_fd('%', 1);
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
	int	*ptr;

	*ptr = 22;
	ft_printf("%p", ptr );
	return (0);
}
*/