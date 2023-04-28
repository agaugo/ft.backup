#include "../include/push_swap.h"

// int	*convert_to_int(t_stack **stack, int size)
// {
// 	int	i;
// 	int	*array;
// 	t_stack *scan_node;

// 	array = malloc(sizeof(int) * size);
// 	if (!array)
// 		return (0);
// 	scan_node = *stack;
// 	i = 0;
// 	while (scan_node->next != NULL)
// 	{
// 		array[i] = ft_atoi(scan_node->content);
// 		scan_node = scan_node->next;
// 		i++;
// 	}
// 	return (array);
// }

t_stack	*find_smallest(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*node;

	temp = *stack;
	node = (*stack)->next;
	while(node)
	{
		if (ft_atoi(temp->content) > ft_atoi(node->content) && node->index == -1)
			temp = node;
		node = node->next;
	}
	return (temp);
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

