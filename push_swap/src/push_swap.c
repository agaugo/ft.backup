/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c		                                :+:    :+: */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:00:44 by hflohil-       #+#    #+#                */
/*   Updated: 2023/03/24 18:59:05 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	**convert_to_int(int argc, char *argv[])
{
	int	**int_array;
	int	i;

	i = 0;
	int_array = malloc(sizeof(int *) * (argc - 1));
	if (!int_array)
		return (0);
	while (i < argc)
	{
		int_array[i] = malloc(sizeof(int));
		if (!int_array[i])
			return (0);
		*int_array[i] = ft_atoi(*argv);
		i++;
	}
	return (int_array);
}

int main(int argc, char *argv[])
{
	t_stack	**stack_a;
	// t_stack *current_node;
	int		**int_array;
	int		i;

	i = 0;
	if (argc == 1)
	{
		write(1, "Error: no input.\n", 17);
		return (0);
	}
	int_array = convert_to_int(argc, argv);
	stack_a = malloc(sizeof(t_stack*));
	if (!stack_a)
		return (0);
	while (i < argc)
 		ft_lstadd_back(stack_a, ft_lstnew(int_array[i]));
   	// current_node = *stack_a;
    // while (current_node->next != NULL)
    // {
    // 	printf("%d", current_node->content);
    //  	current_node = current_node->next;
    // }
    return (0);
}
