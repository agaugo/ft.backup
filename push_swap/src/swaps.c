#include "../include/push_swap.h"
#include <stdio.h>

int rotate(t_stack **stack, char id)
{
    t_stack *last;
    t_stack *node;

	last = *stack;
    while (last->next != NULL)
        last = last->next;
	node = *stack;
    *stack = node->next;
    node->next = NULL;
    last->next = node;
	// printf("%s\n", (*stack)->content);
	// printf("%s\n", node->content);
	// printf("%s\n", last->content);
    if (id == 'a')
        write(1, "ra\n", 3);
    else
        write(1, "rb\n", 3);
    return (1);
}

int	swap(t_stack **stack, char id)
{
	t_stack	*node;
	t_stack *next;
	char	*temp;

	node = *stack;
	next = node->next;
	temp = node->content;
	node->content = next->content;
	next->content = temp;
	if (id == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	return (1);
}