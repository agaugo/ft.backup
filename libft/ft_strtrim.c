/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 13:41:52 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/20 13:41:53 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buffer;

	buffer = malloc(sizeof(char const) * ft_strlen(s1));
	if (!buffer)
		return (0);
	return (buffer);
}
/*
int	main(void)
{
	printf("$%s$\n", ft_strtrim("lorem ipsum dolor sit amet", "te"));
	return (0);
}
*/