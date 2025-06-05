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
	print_stack(stack_a, "A");
	push_swap(&stack_a, &stack_b);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	// sort_up_to_five(&stack_a);
	//  pb(&stack_a, &stack_b);
	//  pb(&stack_a, &stack_b);
	//  print_stack(stack_b, "b");
	//  print_stack(stack_a, "A");
	//  rrr(&stack_a, &stack_b);
	//  print_stack(stack_a, "A");
	//  print_stack(stack_b, "b");
	//  rr(&stack_a, &stack_b);
	//  print_stack(stack_a, "A");
	//  print_stack(stack_b, "b");
	// ss(&stack_a, &stack_b);
	// print_stack(stack_a, "A after sa");
	// print_stack(stack_a, "A");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
