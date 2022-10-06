/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:36:22 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/04 17:06:01 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	i;
	unsigned char	*s;

	s = b;
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	b = s;
	return (b);
}

/*
int main(void)
{
	char b[5] = {'1','2','3','4','5'};
	printf("%s\n", ft_memset(b, 'x', 4));
	printf("%s\n", memset(b, 'x', 4));
	return (0);
}
*/
