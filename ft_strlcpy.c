/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:32:47 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/05 16:07:24 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' || i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char test[10];
	printf("%zu\n", strlcpy(test, "dude", 3));
	printf("%zu\n", ft_strlcpy(test, "dude", 3));
	return (0);
}
*/
