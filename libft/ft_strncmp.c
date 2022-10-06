/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:56:15 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 16:17:24 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned int	size;

	index = 0;
	size = 0;
	while (index < n && s1[index] != '\0')
	{
		if (s1[index] > s2[index])
			size++;
		else if (s1[index] < s2[index])
			size--;
		index++;
	}
	return (size);
}
/*
int	main(void)
{
	char s1[5] = "oaaaa";
	char s2[5] = "oadaa";
	printf("%d\n", ft_strncmp(s1, s2, 5));
    printf("%d\n", strncmp(s1, s2, 5));
	return 0;
}
*/
