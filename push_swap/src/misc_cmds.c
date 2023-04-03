/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c		                                :+:    :+: */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:00:44 by hflohil-       #+#    #+#                */
/*   Updated: 2023/03/09 14:00:44 by hflohil-       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_largest(int *array, int size)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while(i < size)
	{
		if (temp < array[i])
			temp = array[i];
		i++;
	}
	return (temp);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				base;
	int				sign;

	base = 0;
	sign = 1;
	while (*str != '\0')
	{
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (ft_isdigit(*str))
		{
			base *= 10;
			base += *(str) - '0';
			str++;
		}
		break ;
	}
	return (base * sign);
}
