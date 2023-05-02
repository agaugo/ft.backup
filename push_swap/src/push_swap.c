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

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*scan_a;
	int		size;
	int		i;

	i = 0;
	scan_a = *stack_a;
	while (!in_order(stack_a))
	{
		size = ft_lstsize(*stack_a);
		while (size--)
		{
			scan_a = *stack_a;
			if ((scan_a->index >> i) & 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		push_all(stack_b, stack_a, 'a');
		i++;
	}
}

void	fill_index(t_stack **stack_a)
{
	int		i;
	int		size;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < size)
	{
		find_smallest(stack_a)->index = i;
		i++;
	}
}

void	select_alg(int argc, char *argv[], t_stack **stack_a, t_stack **stack_b)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 1;
	while (i < argc)
	{
		temp = argv[i];
		ft_lstadd_back(stack_a, ft_lstnew(temp, -1));
		i++;
	}
	fill_index(stack_a);
	if (argc <= 4)
		sort_three(stack_a);
	else if (argc > 4 && argc <= 6)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = malloc(sizeof(t_stack *));
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	if (argc == 1)
	{
		write(1, "Error: no input.\n", 17);
		return (0);
	}
	select_alg(argc, argv, stack_a, stack_b);
	return (0);
}
