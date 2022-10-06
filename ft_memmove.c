/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 10:34:44 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 12:36:34 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*typec_src;
	unsigned char	*typec_dst;
	unsigned char	*temp;

	typec_src = (unsigned char *)src;
	typec_dst = (unsigned char *)dst;
	temp = typec_src;
	index = 0;
	while (index < len)
	{
		typec_dst[index] = temp[index];
		index++;
	}
	dst = typec_dst;
	return (dst);
}

/*
int main(void)
{
    char    str[] = "aabbcc";
    char    str2[] = "aabbcc";

    printf("%s\n", ft_memmove(str, str + 2, 1));
    printf("%s\n", memmove(str2, str2 + 2, 1));
    return (0);
}
*/
