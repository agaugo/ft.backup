#include "../include/push_swap.h"
#include <stdio.h>

/*
swap(stack, id)

sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/

void	swap(t_stack **stack, char id)
{
	t_stack *second;

	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = (*stack);
	(*stack) = second;
	if (id != 'x')
		printf("s%c\n", id);
}

/*
push (stack a, stack b, id)

pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
*/

void	push(t_stack **source, t_stack **target, char id)
{
	t_stack	*new_node;

	new_node = ft_lstnew((*source)->content);
	ft_lstadd_front(target, new_node);
	ft_delfirst(source);
	printf("p%c\n", id);
}
//rotate(stack, id)
void	rotate(t_stack **stack, char id)
{
	t_stack *last_node;
	t_stack *first_node;


	first_node = *stack;
	last_node = *stack;
	*stack = (*stack)->next;
	while (last_node->next != NULL)
	{
		printf("last_node->content = %s\n", (char*)last_node->content);
		last_node = last_node->next;
	}
	printf("last_node->content = %s\n", (char*)last_node->content);

	last_node->next = first_node;

	first_node->next = NULL;

	printf("r%c\n", id);
}
//rev_rotate(stack, id)

