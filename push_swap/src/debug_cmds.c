#include "../include/push_swap.h"
#include <stdio.h>

int	in_order(t_stack **stack)
{
	t_stack *node;
	t_stack	*next;

	node = malloc(sizeof(t_stack *));
	next = malloc(sizeof(t_stack *));
	if (!node || !next)
		return (0);
	node = *stack;
	next = node->next;
	while (next->next != NULL)
	{
		if (node->content >= next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	print_stack(t_stack **stack, char *id)
{
	t_stack	*current_node;

	current_node = *stack;
// for debugging:
	printf("STACK: %s\n", id);
	while (current_node->next != NULL)
	{
		printf("| %s ", (char*)current_node->content);
		current_node = current_node->next;
	}
	printf("\n");
	return (1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_strdup(const char *s1)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = malloc(ft_strlen(s1) + 1);
	if (!buffer)
		return (0);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

