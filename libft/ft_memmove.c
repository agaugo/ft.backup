/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 10:34:44 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/07 16:18:10 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_buffer;
	unsigned char	*src_buffer;
	unsigned char	*temp_buffer;
	size_t			size;

	dst_buffer = (unsigned char *)dst;
	src_buffer = (unsigned char *)src;
	*temp_buffer = *src_buffer;

	if ((temp_buffer == '\0') || (*dst_buffer == '\0' && *src_buffer == '\0')
		|| (*dst_buffer == '\0' && *src_buffer == '\0' && len == '\0'))
		return (0);



}
/*
int main(void)
{
    char    str[20] = "aabbcc";
    char    str2[20] = "aabbcc";

	printf("%s\n", ft_memmove(str, str+2, sizeof(str)));
//	printf("%s\n", memmove(0, 0, 0));
    return (0);
}

*/
