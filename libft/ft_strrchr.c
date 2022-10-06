/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:39:00 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:52:11 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char			*target;
	char			c_char;
	unsigned int	len;

	len = 0;
	target = (char *)s;
	c_char = (char)c;
	while (target[len] != '\0')
		len++;
	while (len >= 0)
	{
		if (*(target + len) == c_char)
			return (target + len);
		len--;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[30] = "abcdeeeefff";
	printf("%s\n", ft_strrchr(str, 'e'));
    printf("%s\n", strrchr(str, 'e'));
	return 0;
}
*/
