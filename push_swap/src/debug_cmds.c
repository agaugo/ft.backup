#include "../include/push_swap.h"
#include <stdio.h>

void	print_stack(t_stack **stack, char *id)
{
	t_stack	*current_node;

	current_node = malloc(sizeof(t_stack));
	if (!current_node)
		free(current_node);
	current_node = *stack;
// for debugging:
	printf("STACK: %s\n", id);
	while (current_node->next != NULL)
	{
		printf("| %d ", *(int*)current_node->content);
		current_node = current_node->next;
	}
	printf("\n");
}
