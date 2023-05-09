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
