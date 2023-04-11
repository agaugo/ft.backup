#include "../include/push_swap.h"
#include <stdio.h>


void	micro_alg(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack	*node;
	int	size;

	node = *stack_a;
	size = ft_lstsize(node) - 1;
	if (!in_order(stack_a))
	{
		if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_a)->next->content))
		{
			swap(stack_a, 'a');
			push(stack_a, stack_b, 'b');
		}
		while (size > 1)
		{
			if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_a)->next->content))
			{
				swap(stack_a, 'a');
				push(stack_a, stack_b, 'b');
			}
			else
				push(stack_a, stack_b, 'b');
			size--;
		}
		push(stack_a, stack_b, 'b');
		size = ft_lstsize(*stack_b);
		while (size > 1)
		{
			push(stack_b, stack_a, 'a');
			size--;
		}
		push(stack_b, stack_a, 'a');
	}
	if (!in_order(stack_a))
		micro_alg(stack_a, stack_b);
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
	print_stack(stack_a, "A");
	if (argc == 3 && !in_order(stack_a))
		swap(stack_a, 'a');
	if (argc <= 5)
		micro_alg(stack_a, stack_b);
	print_stack(stack_a, "A");
    return (0);
}
