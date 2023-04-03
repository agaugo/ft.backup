/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c		                                :+:    :+:			  */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:00:44 by hflohil-       #+#    #+#                */
/*   Updated: 2023/03/24 18:59:05 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	init_load(int *array, int size)
{
	printf("largest: %d", find_largest(array, size));
}

void convert_to_int(int *array, int argc, char *argv[])
{
	int	i;

	i = 0;
	argv++;
	while (i < argc - 1)
	{
		array[i] = ft_atoi(*argv);
		argv++;
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_stack	**stack_a;
	int		*int_array;
	int		*temp;
	int		i;

	i = 0;
	if (argc == 1)
	{
		write(1, "Error: no input.\n", 17);
		return (0);
	}

	//dont forget to protect:
	int_array = malloc(sizeof(int) * argc - 1);
	stack_a = malloc(sizeof(t_stack*));

	convert_to_int(int_array, argc, argv);
	temp = NULL;
	while (i < argc)
	{
		temp = &int_array[i];
		ft_lstadd_back(stack_a, ft_lstnew(temp));
		i++;
	}
	print_stack(stack_a, "A");
	init_load(int_array, argc-1);
    return (0);
}
