#include "../include/push_swap.h"

int	*convert_to_int(t_stack **stack, int size)
{
	int	i;
	int	*array;
	t_stack *scan_node;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (0);
	scan_node = *stack;
	i = 0;
	while (scan_node->next != NULL)
	{
		array[i] = ft_atoi(scan_node->content);
		scan_node = scan_node->next;
		i++;
	}
	return (array);
}

int	find_largest(int *array, int size)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while(i < size)
	{
		if (temp < array[i])
			temp = array[i];
		i++;
	}
	i = 0;
	if (temp == 0)
		return (1);
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				base;
	int				sign;

	base = 0;
	sign = 1;
	while (*str != '\0')
	{
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (ft_isdigit(*str))
		{
			base *= 10;
			base += *(str) - '0';
			str++;
		}
		break ;
	}
	return (base * sign);
}

