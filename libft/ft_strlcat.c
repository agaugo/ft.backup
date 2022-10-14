/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 14:36:09 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/13 14:36:09 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	limit;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);

	printf("%s\n", "hit #1");

	limit = dstsize - 1;
	i = 0;
	if (dstsize == 0)
		printf("%s\n", "hit #2");
		return (src_len);

	if ((int)dstsize < (int)src_len)
		printf("%s\n", "hit #3");
		return (src_len + dst_len);

	printf("%s\n", "hit #4");

	while (limit > 0 && --limit && i <= src_len)
	{
		printf("%s\n", "hit #5");
		dst[dst_len + i] = src[i];
		i++;
	}

	printf("%s\n", "hit #6");
	return (1);	
}

int	main(void)
{
	char dest[13] = "a";
//	char dest2[14] = "a";

	ft_strlcat(dest, "lorem ipsum dolor sit amet", 12);
//	printf("%zu\n", strlcat(dest2, "lorem ipsum dolor sit amet", 14));
//	printf("%s\n", dest);
//	printf("%s\n", dest2);

	return 0;
}
*/