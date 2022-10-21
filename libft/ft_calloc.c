/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 18:30:12 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/19 18:30:13 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buffer;
	int		i;

	buffer = malloc(count * size);
	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
		buffer[i++] = '\0';
	return (buffer);
}
