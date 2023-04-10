#include "../include/push_swap.h"
#include <stdio.h>

// void	big_data()
// {

// }
void		small_data(t_stack	**stack_a, t_stack	**stack_b)
{
	swap(stack_a, 'a');
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	push(stack_a, stack_b, 'b');
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	rotate(stack_a, 'a');
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");


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
		ft_lstadd_back(stack_a, ft_lstnew(temp));
		ft_lstadd_back(stack_b, ft_lstnew(temp));
		i++;
	}
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	if  (argc <= 20)
		small_data(stack_a, stack_b);
    return (0);
}
