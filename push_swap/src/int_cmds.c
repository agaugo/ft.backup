#include "../include/push_swap.h"
#include <stdio.h>

t_stack *find_smallest(t_stack **stack)
{
	t_stack *node;
	t_stack *temp;

	node = *stack;
	temp = NULL;
	while (node)
	{
		if (temp == NULL && node->index == -1)
			temp = node;
		if (node->index == -1 && ft_atoi(node->content) < ft_atoi(temp->content))
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

