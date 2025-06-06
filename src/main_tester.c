#include "../includes/push_swap.h"

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
	print_stack(stack_a, "A");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
