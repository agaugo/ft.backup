#include "../include/push_swap.h"
#include <stdio.h>

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;


	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a>b && b<c && a<c)
		swap(stack_a, 'a');
	else if (a>b && b>c && a>c)
	{
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	else if (a>b && b<c && a>c)
		rotate(stack_a, 'a');
	else if (a<b && b>c && a<c)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (a<b && b>c && a>c)
		rev_rotate(stack_a, 'a');
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
	sort_three(stack_a);
}

void	push_all(t_stack **source, t_stack **target, char id)
{
	while (*source)
		push(source, target, id);
}

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

int main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack **stack_b;
	char	*temp = NULL;
	int		i;

	i = 1;
	if (argc == 1)
	{
		write(1, "Error: no input.\n", 17);
		return (0);
	}
	stack_a = malloc(sizeof(t_stack*));
	stack_b = malloc(sizeof(t_stack*));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	while (i < argc)
	{
		temp = argv[i];
		ft_lstadd_back(stack_a, ft_lstnew(temp, -1));
		i++;
	}
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	fill_index(stack_a);
	if (argc <= 4)
		sort_three(stack_a);
	else if (argc > 4 && argc <= 6)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
    return (0);
}
