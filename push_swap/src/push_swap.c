#include "../include/push_swap.h"
#include <stdio.h>

// void	merge_sort(t_stack **stack_a, int max_digits)
// {

// }

int main(int argc, char *argv[])
{
	t_stack	**stack_a;
	char	*temp = NULL;
	int		i;
	int		max_digits;

	i = 0;
	if (argc == 1)
	{
		write(1, "Error: no input.\n", 17);
		return (0);
	}
	stack_a = malloc(sizeof(t_stack*));
	if (!stack_a)
		return (0);
	*stack_a = NULL;
	i++;
	while (i <= argc)
	{
		temp = argv[i];
		ft_lstadd_back(stack_a, ft_lstnew(temp));
		i++;
	}
	print_stack(stack_a, "A");
	printf("size of stack: %d\n", argc - 1);
	max_digits = find_largest(convert_to_int(stack_a, argc - 1), argc - 1);
	printf("maxdigits: %d", max_digits);

	// radix_sort(stack_a, max_digits);
    return (0);
}
