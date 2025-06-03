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
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
	{
		free_stack(stack_a);
		return (1);
	}
	stack_b->top = NULL;
	stack_b->size = 0;
	print_stack(stack_a, "A");
	sa(stack_a);
	print_stack(stack_a, "A after sa");
	print_stack(stack_b, "b");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
