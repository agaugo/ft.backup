/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c		                                :+:    :+: */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:00:44 by hflohil-       #+#    #+#                */
/*   Updated: 2023/03/09 14:00:44 by hflohil-       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack *current_node;

	if (argc == 1)
	{
		write(1, "Error: no input.\n", 17);
		return (0);
	}
	stack_a = malloc(sizeof(t_stack*));
	if (!stack_a)
		return (0);
	argv++;
	while (argc--)
	{
		ft_lstadd_back(stack_a, ft_lstnew(*argv));
		argv++;
	}
	current_node = *stack_a;
	while (current_node->next != NULL)
	{
		printf("%s", (char *)current_node->content);
		current_node = current_node->next;
	}
	return (0);
}
