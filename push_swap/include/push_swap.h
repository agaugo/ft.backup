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
  int index;
  struct s_stack *next;
} t_stack;

//list commands
t_stack *ft_lstnew(void *content, int index);
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
t_stack *find_smallest(t_stack **stack);
t_stack	*find_highest_index(t_stack	**stack);
int	    *convert_to_int(t_stack **stack, int size);
int	    in_order(t_stack **stack);
int     index_check(t_stack **stack);

//Prints
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);


//debugging
int	    print_stack(t_stack **stack, char *id);

//main
void    radix_sort(t_stack **stack_a, t_stack **stack_b);
void    fill_index(t_stack **stack);
void    small_sort(t_stack **stack_a, t_stack **stack_b);

//swaps
void	  push(t_stack **source, t_stack **target, char id);
void	  swap(t_stack **stack, char id);
void	  rotate(t_stack **stack, char id);
void	  rev_rotate(t_stack **stack, char id);
void    push_all(t_stack **source, t_stack **target, char id);

