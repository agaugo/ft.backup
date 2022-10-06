/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:07:45 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/05 16:24:17 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (i < dstsize)
		i++;
	while (src[x] != '\0')
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = '\0';
	return (i);
}

int	main(void)
{
	char test[100];
	printf("%d", ft_strlcat());
	printf();
}
