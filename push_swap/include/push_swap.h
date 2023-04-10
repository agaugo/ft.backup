/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h		                                :+:    :+: */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:00:44 by hflohil-      #+#    #+#                 */
/*   Updated: 2023/03/09 14:00:44 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

//node structure
typedef struct s_stack {
  void *content;
  struct s_stack *next;
} t_stack;

//list commands
t_stack *ft_lstnew(void *content);
void    ft_lstadd_front(t_stack **lst, t_stack *new_node);
int     ft_lstsize(t_stack *lst);
t_stack *ft_lstlast(t_stack *lst);
void    ft_lstadd_back(t_stack **lst, t_stack *new_node);
void    ft_lstdelone(t_stack *node);
void    ft_lstclear(t_stack **lst, void (*del)(void *));
void	  ft_delfirst(t_stack **stack_a);

//int manipulation and reads
int   	ft_isdigit(int c);
int	    ft_atoi(const char *str);
int	    find_largest(int *array, int size);
int	    *convert_to_int(t_stack **stack, int size);
int	    in_order(t_stack **stack);


//debugging
int	    print_stack(t_stack **stack, char *id);

//main
void		small_data(t_stack	**stack_a, t_stack	**stack_b);

//swaps
void	  push(t_stack **source, t_stack **target, char id);
void	  swap(t_stack **stack, char id);
void	   rotate(t_stack **stack, char id);
