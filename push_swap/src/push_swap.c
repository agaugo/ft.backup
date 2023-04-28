#include "../include/push_swap.h"
#include <stdio.h>

void	radix(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack *node;

	node = *stack_a;
// Puts all negative numbers in stack B to be sorted seperately.
	while (node)
	{
		if (ft_atoi(node->content) < 0)
		{
			while (*stack_a != node)
				rotate(stack_a, 'a');
			push(stack_a, stack_b, 'b');
		}
		node = node->next;
	}
}


int main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack **stack_b;
	char	*temp = NULL;
	int		i;

	i = 1;
	if (argc == 1)
	{
		write(1, "Error: no input.\n", 17);
		return (0);
	}
	stack_a = malloc(sizeof(t_stack*));
	stack_b = malloc(sizeof(t_stack*));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	while (i < argc)
	{
		temp = argv[i];
		ft_lstadd_back(stack_a, ft_lstnew(temp));
		i++;
	}
	// if (argc == 3 && !in_order(stack_a))
	// 	swap(stack_a, 'a');
	if (argc <= 5)
		radix(stack_a, stack_b);
    return (0);
}
