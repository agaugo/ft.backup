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

char *reverse(char *buffer, int i)
{
    int c;
    int end;
    char temp;

    c = 0;
    end = i;
    while (i != c)
    {
        temp = buffer[i];
        buffer[i] = buffer[c];
        buffer[c] = temp;
        i--;
        c++; 
    }
    buffer[end + 1] = '\0';
    return (buffer);
}

char *ft_itoa(int n)
{
    int     i;
    int     x;
    char    *buffer;

    i  = 0;
    x = 0;
    buffer = malloc(sizeof(char) * 12);
    if (!buffer)
        return (0);
    if (n < 0)
    {
        x = -1;
        n *= -1;
    }
    while (n != 0)
    {
        buffer[i] = (n % 10) + '0';
        n -= n % 10;
        n = n / 10;
        i++;
    }
    if (x == -1)
    {
        buffer[i] = '-';
        i++;
    }
    return (reverse(buffer, i));
}

int main(void)
{
    printf("$%s$\n", ft_itoa(12345));
    return 0;
}