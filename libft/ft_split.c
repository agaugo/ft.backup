/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/22 19:32:49 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/22 19:32:50 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_mem(char **buffer_array, int i)
{
	while (i >= 0)
	{
		free(buffer_array[i]);
		i--;
	}
	free(buffer_array);
}

int	substr_size(const char *s, char c, int start)
{
	int	size;

	size = 0;
	while (s[start + size] != c && s[start + size] != '\0')
		size++;
	return (size);
}

char	**fill_array(const char *s, char **buffer_array, int elements_cnt, int c)
{
	int	i;
	int	start;
	int	size;

	i = 0;
	start = 0;
	size = 0;
	while (i < elements_cnt)
	{
		while (s[start + size] == c && s[start] != '\0')
			start++;
		start += size;
		size = substr_size(s, c, start);
		buffer_array[i] = ft_substr(s, start, substr_size(s, c, start));
		if (!buffer_array[i])
		{
			free_mem(buffer_array, i);
			return (NULL);
		}
		i++;
	}
	buffer_array[i] = 0;
	return (buffer_array);
}

int	str_counter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            count++;
            while (s[i] != c && s[i])
                i++;
        }
        else
            i++;
    }
    return (count);
}

char	**ft_split(char const *s, char c)
{
	int		elements_cnt;
	char	**buffer_array;

	if (!s)
		return (NULL);
	elements_cnt = str_counter(s, c);
	buffer_array = (char **)malloc(sizeof(char *) * (elements_cnt + 1));
	if (!buffer_array)
	{
		free(buffer_array);
		return (NULL);
	}
	buffer_array = fill_array(s, buffer_array, elements_cnt, c);
	return (buffer_array);
}

/*
int	main(void)
{
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[0]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[1]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[2]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[3]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[4]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[5]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[6]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[7]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[8]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[9]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[10]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[11]);
	printf("%s\n", ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[12]);

	return (0);
}
*/