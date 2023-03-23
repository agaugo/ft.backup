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

// Add node to the end of the list, tail.
void ft_lstadd_back(t_stack **lst, t_stack *new_node) {
  t_stack *tail;

  if (!new_node)
    return;
  if (!*lst) {
    *lst = new_node;
    return;
  }
  tail = ft_lstlast(*lst);
  tail->next = new_node;
}

// Add node to the front of the list, head.
void ft_lstadd_front(t_stack **lst, t_stack *new_node) {
  new_node->next = *lst;
  *lst = new_node;
}

// Clears and frees entire list.
void ft_lstclear(t_stack **lst, void (*del)(void *)) {
  t_stack *next_temp;
  t_stack *node;

  if (!*lst || !*del)
    return;
  node = *lst;
  next_temp = node->next;
  while (next_temp != NULL) {
    ft_lstdelone(node, del);
    node = next_temp;
    next_temp = node->next;
  }
  ft_lstdelone(node, del);
  *lst = NULL;
}

// Clears and frees a singular Node.
void ft_lstdelone(t_stack *lst, void (*del)(void *)) {
  if (!lst)
    return;
  del(lst->content);
  free(lst);
}

// Returns a pointer to the last Node in the list.
t_stack *ft_lstlast(t_stack *lst) {
  if (!lst)
    return (NULL);
  while (lst->next != NULL)
    lst = lst->next;
  return (lst);
}

// Creates a new list containing a pointer, specified in parameters.
t_stack *ft_lstnew(void *content) {
  t_stack *node;

  node = (t_stack *)malloc(sizeof(t_stack));
  if (!node)
    return (NULL);
  node->content = content;
  node->next = NULL;
  return (node);
}

// Returns the size of the list (i.e. the amount of Nodes).
int ft_lstsize(t_stack *lst) {
  int cnt;
  t_stack *temp;

  temp = lst;
  cnt = 0;
  while (temp != NULL) {
    temp = temp->next;
    cnt++;
  }
  return (cnt);
}
