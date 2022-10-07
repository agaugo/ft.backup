/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:07:45 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 18:13:25 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (dst[i] != '\0')
		i++;
	while (src[x] != '\0' && i < dstsize)
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = '\0';
	return (i);
}
/*
int	main(void)
{
	char	string[20]	=	"bri";
	char	source[5]	=	"abcd";
    char    stringb[20]	=	"bri";
    char    sourceb[5]	=	"abcd";
	printf("%zu\n", ft_strlcat(string, source, 20));
	printf("%zu\n", strlcat(stringb, sourceb, 20));
	printf("%s\n", string);
	printf("%s\n", stringb);
	return (0);
}
*/
