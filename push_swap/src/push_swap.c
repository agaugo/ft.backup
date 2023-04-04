#include "../include/push_swap.h"
#include <stdio.h>

// void	merge_sort(t_stack **stack_a, int max_digits)
// {

// }

int		small_data(t_stack	**stack_a)
{
	t_stack	**stack_b;
	t_stack	*node;
	t_stack *next;
	t_stack *last;
	int	i = 1;

	stack_b = malloc(sizeof(t_stack*));
	node = malloc(sizeof(t_stack*));
	next = malloc(sizeof(t_stack*));
	last = malloc(sizeof(t_stack*));
	if (!stack_b || !node || !next || !last)
		return (0);
	node = *stack_a;
	next = node->next;
	last = next->next;
	// printf("%d", ft_atoi(node->content));
	// printf("%d", ft_atoi(node->content));
	while (i--)
	{
		if (ft_atoi(node->content) >= ft_atoi(next->content))
		{
			swap(stack_a, 'a');
			print_stack(stack_a, "A");
			rotate(stack_a, 'a');
		}
	}
	print_stack(stack_a, "A");
	return (1);
}

int main(int argc, char *argv[])
{
	t_stack	**stack_a;
	char	*temp = NULL;
	int		i;

	i = 0;
	if (argc == 1)
	{
		write(1, "Error: no input.\n", 17);
		return (0);
	}
	stack_a = malloc(sizeof(t_stack*));
	if (!stack_a)
		return (0);
	*stack_a = NULL;
	i++;
	while (i <= argc)
	{
		temp = argv[i];
		ft_lstadd_back(stack_a, ft_lstnew(temp));
		i++;
	}
	print_stack(stack_a, "A");
	if  (argc <= 5)
		small_data(stack_a);
    return (0);
}
