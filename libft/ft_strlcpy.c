/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:32:47 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 10:30:01 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	while (i < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
/*
int	main(void)
{
	char test[10] = "assoof";
	char test2[10] = "assoof";
	printf("%lu\n", strlcpy(test, "gnup", sizeof(test)));
	printf("%lu\n", ft_strlcpy(test2, "gnup", sizeof(test2)));
	return (0);
}
*/
