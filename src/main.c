/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:16:59 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/11 13:17:46 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	exec_push_swap(t_node **stack_a, t_node **stack_b)
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
		return (ft_putendl_fd("Error", 2), 1);
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
