#include "../include/push_swap.h"
#include <stdio.h>

int	print_stack(t_stack **stack, char *id)
{
	t_stack	*current_node;

	current_node = malloc(sizeof(t_stack));
	if (!current_node)
		return (0);
	current_node = *stack;
// for debugging:
	printf("STACK: %s\n", id);
	while (current_node->next != NULL)
	{
		printf("| %s ", (char*)current_node->content);
		current_node = current_node->next;
	}
	printf("\n");
	return (1);
}
