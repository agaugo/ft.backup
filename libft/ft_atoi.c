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

int	ft_atoi(const char *str)
{
	int				res;
	int				mul;

	res = 0;
	mul = 1;
	while (*str != '\0' && *str != '\e')
	{
		if ((!(*str >= '0' && *str <= '9')
				&& (*(str - 1) >= '0' && *(str - 1) <= '9'))
			|| (!(*str >= '0' && *str <= '9') && !((*str >= 9 && *str <= 13)
					|| *str == 32) && !(*str == '-' || *str == '+'))
			|| ((*str == '-' || *str == '+') && !(*(str + 1) >= '0'
					&& *(str + 1) <= '9')))
			break ;
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
	printf("%d\n", ft_atoi("+47+5"));
	printf("%d\n", atoi("+47+5"));
	return (0);
}
*/