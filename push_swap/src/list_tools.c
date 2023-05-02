/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 19:37:46 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/14 19:37:46 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

// Add node to the front of the list, head.
void	ft_lstadd_front(t_stack **lst, t_stack *new_node)
{
	new_node->next = *lst;
	*lst = new_node;
}

void	ft_delfirst(t_stack **stack)
{
	t_stack	*temp;

	if (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		ft_lstdelone(temp);
	}
}

// Clears and frees a singular Node.
void	ft_lstdelone(t_stack *node)
{
	if (!node)
		return ;
	free(node);
	node = NULL;
}

// Returns a pointer to the last Node in the list.
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
