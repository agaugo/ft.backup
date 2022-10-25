/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/22 19:32:49 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/22 19:32:50 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size(int n)
{
	int x;

	x = 0;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		x += 1;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		++x;
	}
	return (x);
}

char	*reverse(char *buffer, int i)
{
	int		c;
	char	temp;

	c = 0;
	i -= 1;
	while (i >= c)
	{
		temp = buffer[i];
		buffer[i] = buffer[c];
		buffer[c] = temp;
		i--;
		c++;
	}
	return (buffer);
}

char	*itoa_plus(char *buffer, int n)
{
	int	x;
	int i;

	x = 0;
	i = 0;
	if (n < 0)
	{
		x = -1;
		n *= -1;
	}
	while (n != 0)
	{
		buffer[i] = (n % 10) + '0';
		n -= n % 10;
		n = n / 10;
		i++;
	}
	if (x == -1)
		buffer[i++] = '-';
	buffer[i] = '\0';
	return (reverse(buffer, i));
}

char	*ft_itoa(int n)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * size(n) + 1);	
	if (!buffer)
		return (0);
	if (n == -2147483648)
	{
		buffer = "-2147483648";
		return (buffer);
	}
	if (n == 0)
	{
		buffer = "0";
		return (buffer);
	}
	else
		return (itoa_plus(buffer, n));
}
/*
int main(void)
{
    printf("$%s$\n", ft_itoa(-283728));
    return 0;
}
*/