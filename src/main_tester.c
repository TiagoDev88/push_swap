#include "../includes/push_swap.h"
#include <stdio.h>

static void print_stack(t_node *stack, char *name)
{
    t_node *current;

    ft_printf("Stack %s:\n", name);
    current = stack;
    while (current)
    {
        ft_printf("value: %d | index: %d\n", current->value, current->index);
        current = current->next;
    }
    ft_printf("------\n");
}

static void print_stacks_side_by_side(t_node *stack_a, t_node *stack_b)
{
	t_node *node_a = stack_a ? stack_a : NULL;
	t_node *node_b = stack_b ? stack_b : NULL;

	printf(" Index | Stack A | Stack B\n");
	printf("-------|---------|--------\n");

	int i = 0;
	while (node_a || node_b)
	{
		printf(" [%3d] | ", i++);

		if (node_a)
		{
			printf("%7d | ", node_a->value);
			node_a = node_a->next;
		}
		else
			printf("%7s | ", "---");

		if (node_b)
		{
			printf("%7d\n", node_b->value);
			node_b = node_b->next;
		}
		else
			printf("%7s\n", "---");
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (!validate_args(argc, argv))
		return (ft_putendl_fd("Error", 2), 1);
	stack_a = init_stack(argc, argv);
	if (!stack_a)
		return (ft_putendl_fd("Error", 2), 1);
	if (is_order(stack_a))
		return (0);
	push_swap(&stack_a, &stack_b);
	print_stacks_side_by_side(stack_a, stack_b);
	print_stack(stack_a, "A");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
