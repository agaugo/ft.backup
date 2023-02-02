/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_aux.c                                       	:+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:12:58 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:17:13 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//reverses the string given as input and returns the reversed string. Size is passed to know where to null terminate.
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

//converts positive int to uppercase hex
char	*itohex(uintptr_t convert)
{
	char			*hex_result;
	uintptr_t		remainder;
	char			hex_char;
	uintptr_t		i;

	if	(convert == 0)
		return (ft_strdup("0"));
	i = 0;
	hex_result = malloc(sizeof(char) * 50);
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

//converts positive int to loweracse hex
char	*sitohex(uintptr_t convert, int ptr)
{
	char			*hex_result;
	uintptr_t		remainder;
	char			hex_char;
	uintptr_t		i;

	i = 0;
	if (ptr == 1)
		write(1, "0x", 2);
	if	(convert == 0)
		return (ft_strdup("0"));
	hex_result = malloc(sizeof(char) * 50);
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

//converts negative int to uppercase hex
//char	*neg_itohex(int convert)
//converts negative int to lowercase hex
//char	*neg_sitohex(int convert)

//counts the number of digits in a number. Used for itou.
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

//Used for itou, fills a string based on a passed parameters.
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

//converts an integer to a string of chars
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
