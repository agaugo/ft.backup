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

void	ft_lstclear(t_stack **stack)
{
	t_stack	*next_temp;
	t_stack	*node;

	if (!*stack)
		return ;
	node = *stack;
	next_temp = node->next;
	while (next_temp != NULL)
	{
		free(node);
		node = next_temp;
		next_temp = node->next;
	}
	free(node);
	*stack = NULL;
}