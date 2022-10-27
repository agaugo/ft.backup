/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 19:12:49 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/19 19:12:50 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buffer;

	i = 0;
	if (len > (size_t)ft_strlen(s))
		len = (size_t)ft_strlen(s);
	if ((int)len < ft_strlen(s))
		buffer = (char *)malloc(len + 1);
	else
		buffer = (char *)malloc(ft_strlen(s) + 1);
	if (!buffer)
		return (0);
	if (!(start >= (unsigned int)ft_strlen(s)))
	{
		while (i < len && s[start] != '\0')
		{
			buffer[i] = s[start];
			i++;
			start++;
		}
	}
	buffer[i] = '\0';
	return (buffer);
}

/*
int	main(void)
{
	printf("%s\n", ft_substr("hello my friend", 3, 8));
	return (0);
}
*/