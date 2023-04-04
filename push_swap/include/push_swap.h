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

// stack manipulation
typedef struct s_stack {
  void *content;
  struct s_stack *next;
} t_stack;
t_stack *ft_lstnew(void *content);
void ft_lstadd_front(t_stack **lst, t_stack *new_node);
int ft_lstsize(t_stack *lst);
t_stack *ft_lstlast(t_stack *lst);
void ft_lstadd_back(t_stack **lst, t_stack *new_node);
void ft_lstdelone(t_stack *lst, void (*del)(void *));
void ft_lstclear(t_stack **lst, void (*del)(void *));

//int manipulation and reads
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
int	find_largest(int *array, int size);
int	*convert_to_int(t_stack **stack, int size);

//debugging
int	print_stack(t_stack **stack, char *id);

//main
void	radix_sort(t_stack **stack_a, int max_digits);
int		small_data(t_stack	**stack_a);


//swaps
int	swap(t_stack **stack, char id);
int	in_order(t_stack **stack);
int	rotate(t_stack **stack, char id);
