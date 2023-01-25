/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_aux.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:12:58 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:17:13 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_chars(char *string)
{
	int	result;

	result = 0;
	while(*string)
	{
		result++;
		string++;
	}
	return (result);
}

char	*reverse_string(char *buffer, int size)
{
	int		index;
	int		r_index;
	char	temp;


	index = 0;
	r_index = size - 1;
	while (index <= r_index)
	{
		temp = buffer[index];
		buffer[index] = buffer[r_index];
		buffer[r_index] = temp;
		index++;
		r_index--;
	}
	buffer[size] = '\0';
	return (buffer);
}

char	*itohex(int convert)
{
	char	*hex_result;
	int		remainder;
	char	hex_char;
	int		i;

	i = 0;
	hex_result = malloc(sizeof(char) * 8);
	while (convert != 0)
	{
		remainder = convert % 16;
		if (remainder < 10)
			hex_char = remainder + 48;
		else
			hex_char = remainder + 55;
		hex_result[i] = hex_char;
		convert = convert / 16;
		i++;
	}
	return(reverse_string(hex_result, i));
}

char	*sitohex(int convert)
{
	char	*hex_result;
	int		remainder;
	char	hex_char;
	int		i;

	i = 0;
	hex_result = malloc(sizeof(char) * 8);
	while (convert != 0)
	{
		remainder = convert % 16;
		if (remainder < 10)
			hex_char = remainder + 48;
		else
			hex_char = remainder + 87;
		hex_result[i] = hex_char;
		convert = convert / 16;
		i++;
	}
	return(reverse_string(hex_result, i));
}

int	chars(unsigned int n)
{
	int	nb;

	nb = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		nb++;
	}
	return (nb);
}

char	*fill_string(unsigned int n, char *buffer, int ri, int i)
{
	if (n == 0)
	{
		*buffer = '0';
		*(buffer + 1) = '\0';
		return (buffer);

	}
	while (i >= 0)
	{
		buffer[i] = n % 10 + '0';
		n -= n % 10;
		n = n / 10;
		i--;
	}
	buffer[ri] = '\0';
	return (buffer);
}

char	*itou(unsigned int n)
{
	char			*buffer;
	int				ri;
	int				i;

	ri = chars(n);
	i = ri - 1;
	buffer = malloc(sizeof(char) * ri + 1);
	if (!buffer)
		return (0);
	return (fill_string(n, buffer, ri, i));
}

char	*print_ptr(void	*arg)
{
	uintptr_t address;
	char	*hex_address;

	address = (uintptr_t)(&arg);
	hex_address = sitohex(address);
	write(1, "0x", 2);
	return (hex_address);	
}