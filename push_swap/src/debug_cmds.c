#include "../include/push_swap.h"
#include <stdio.h>

int	in_order(t_stack **stack)
{
	t_stack *node;
	t_stack	*next;

	node = malloc(sizeof(t_stack *));
	next = malloc(sizeof(t_stack *));
	if (!node || !next)
		return (0);
	node = *stack;
	next = node->next;
	while (next->next != NULL)
	{
		if (node->content >= next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	print_stack(t_stack **stack, char *id)
{
	t_stack	*current_node;

	current_node = *stack;
	printf("STACK: %s\n", id);
	while (current_node != NULL)
	{
		printf("| %s ", (char*)current_node->content);
		current_node = current_node->next;
	}
	printf("\n");
	return (1);
}
