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




static char	**check_args(int argc, char **argv, int *new_argc)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			return (free_array(args), NULL);
		*new_argc = 0;
		while (args[*new_argc])
			(*new_argc)++;
	}
	else
	{
		args = &argv[1];
		*new_argc = argc - 1;
	}
	return (args);
}

static void exec_push_swap(t_node **stack_a, t_node **stack_b)
{
	push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		new_argc;

	stack_b = NULL;
	if (argc < 2)
		return (1);
	argv = check_args(argc, argv, &new_argc);
	if (!argv)
		return (ft_putendl_fd("Error", 2),1);
	if (!validate_args(new_argc, argv))
	{
		if (argc == 2)
			free_array(argv);
		return (ft_putendl_fd("Error", 2), 1);
	}
	stack_a = init_stack(new_argc, argv);
	if (argc == 2)
		free_array(argv);
	if (!stack_a)
		return (ft_putendl_fd("Error", 2), 1);
	if (is_order(stack_a))
		return (free_stack(&stack_a), 0);
	exec_push_swap(&stack_a, &stack_b);
	return (0);
}
