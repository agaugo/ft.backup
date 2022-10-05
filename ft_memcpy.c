/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 17:55:31 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/05 15:58:44 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*c;
	unsigned char	*x;

	i = 0;
	c = (unsigned char *) dst;
	x = (unsigned char *) src;
	while (i < n)
	{
		c[i] = x[i];
		i++;
	}
	return (dst);
}

int	main(void)
{
	char	dst[200];

	printf("%s", memcpy(dst, "monke", 4));
	return (0);
}
