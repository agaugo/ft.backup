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

// Add node to the end of the list, tail.
void  ft_lstadd_back(t_stack **lst, t_stack *new_node)
{
  t_stack *tail;

  if (!new_node)
    return;
  if (!*lst)
  {
    *lst = new_node;
    return ;
  }
  tail = ft_lstlast(*lst);
  tail->next = new_node;
}

// Add node to the front of the list, head.
void  ft_lstadd_front(t_stack **lst, t_stack *new_node)
{
  new_node->next = *lst;
  *lst = new_node;
}

void	ft_delfirst(t_stack **stack)
{
	t_stack *temp;

	if (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		ft_lstdelone(temp);
	}
}

// Clears and frees a singular Node.
void ft_lstdelone(t_stack *node)
{
  if (!node)
    return;
  free(node);
  node = NULL;
}

// Returns a pointer to the last Node in the list.
t_stack *ft_lstlast(t_stack *lst)
{
  if (!lst)
    return (NULL);
  while (lst->next != NULL)
    lst = lst->next;
  return (lst);
}

// Creates a new list containing a pointer, specified in parameters.
t_stack *ft_lstnew(void *content, int index) 
{
  t_stack *node;

  node = (t_stack *)malloc(sizeof(t_stack));
  if (!node)
    return (NULL);
  node->content = content;
  if (index == -1)
    node->index = -1;
  else
    node->index = index;
  node->next = NULL;
  return (node);
}

// Returns the size of the list (i.e. the amount of Nodes).
int ft_lstsize(t_stack *lst)
{
  int     cnt;
  t_stack *temp;

  temp = lst;
  cnt = 0;
  while (temp != NULL) {
    temp = temp->next;
    cnt++;
  }
  return (cnt);
}

int	in_order(t_stack **stack)
{
	t_stack *node;
	t_stack	*next;

	node = *stack;
	next = node->next;
	while (next != NULL)
	{
		if ((ft_atoi(node->content) > ft_atoi(next->content)))
			return (0);
		node = node->next;
    next = next->next;
	}
	return (1);
}