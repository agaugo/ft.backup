#include <stdio.h>
#include <stdlib.h>

//binary negation
char    *negate_binary(char *binary)
{
    int     i;

    i = 0;
    while (binary[i])
    {
        if (binary[i] == '0')
            binary[i] = '1';
        else
            binary[i] = '0';
        i++;
    }
    if (binary[15] == '0')
         binary[15] = '1';
    return (binary);
}

//to binary converter
char	*binary(int	convert)
{
	char	*binary_string;
	int		index;
	int		is_neg;

    binary_string = malloc(sizeof(char) * 17);
    if (!binary_string)
        return (0);

    *(binary_string + 16) = '\0';
	index = 15;
    is_neg = 0;
	if (convert < 0)
    {
		convert *= -1;
        is_neg = 1;
    }
	while (convert != 0)
	{
		if (convert % 2 == 1)
			*(binary_string + index) = '1';
		else
			*(binary_string + index) = '0';
        convert = convert / 2;
		index--;
	}
    while (index >= 0)
    {
        *(binary_string + index) = '0';
        index--;
    }
    if (is_neg == 1)
        return (negate_binary(binary_string));
	return (binary_string);
}

int main(void)
{
    printf("%s", binary(-239));
    return (0);
}