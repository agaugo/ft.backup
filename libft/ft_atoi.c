/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 19:37:46 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/14 19:37:46 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ugly_if(char c, char b, char a)
{
	if ((!(c >= '0' && c <= '9')
		&& (b >= '0' && b <= '9'))
	|| (!(c >= '0' && c <= '9') && !((c >= 9 && c <= 13)
			|| c == 32) && !(c == '-' || c == '+'))
	|| ((c == '-' || c == '+') && !(a >= '0'
			&& a <= '9')))
			return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		res;
	int		mul;

	res = 0;
	mul = 1;
	while (*str && ugly_if(*str, *(str - 1), *(str + 1)))
	{
		if (*str == '-' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
			mul *= -1;
		if (*str >= '0' && *str <= '9')
		{
			res *= 10;
			res += *(str) - '0';
		}
		str++;
	}
	return (res * mul);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi(" \t\v\n\r\f123"));
	return (0);
}
*/