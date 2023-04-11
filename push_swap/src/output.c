#include "../include/push_swap.h"
#include <stdio.h>


void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

//FOR DEBUGGING ONLY:
int	print_stack(t_stack **stack, char *id)
{
	t_stack	*current_node;

	if (!(*stack))
		printf("[Stack Empty]");
	else
	{
		current_node = *stack;
		printf("STACK: %s\n", id);
		while (current_node != NULL)
		{
			printf("| %s ", (char*)current_node->content);
			current_node = current_node->next;
		}
	}	
	printf("\n");
	return (1);
}
