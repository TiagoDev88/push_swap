#include "../includes/push_swap.h"

static void print_stack(t_stack *stack, char *name)
{
    t_node *current;

    ft_printf("Stack %s:\n", name);
    current = stack->top;
    while (current)
    {
        ft_printf("value: %d | index: %d\n", current->value, current->index);
        current = current->next;
    }
    ft_printf("------\n");
}



int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (!validate_args(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_a = init_stack(argc, argv);
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
	{
		free_stack(stack_a);
		return (1);
	}
	print_stack(stack_a, "A");
	pb(stack_a, stack_b);
	print_stack(stack_a, "A");
	ss(stack_a, stack_b);
	//print_stack(stack_a, "A after sa");
	print_stack(stack_b, "b");
	print_stack(stack_a, "A");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
