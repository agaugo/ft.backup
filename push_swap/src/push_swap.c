#include "../include/push_swap.h"
#include <stdio.h>

void	fill_index(t_stack **stack_a)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = find_smallest(stack_a);
	while (node)
	{
		node->index = i;
		node = find_smallest(stack_a);
		i++;
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
	fill_index(stack_a);
	print_stack(stack_a, "A");
    return (0);
}
