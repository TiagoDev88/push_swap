/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:58:10 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/08 20:58:04 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/push_swap_bonus.h"

static void	execute_instruction(char *line, t_node **a, t_node **b)
{
	if (!ft_strncmp(line, "sa", ft_strlen(line)))
		sa(a);
	else if (!ft_strncmp(line, "sb", ft_strlen(line)))
		sb(b);
	else if (!ft_strncmp(line, "ss", ft_strlen(line)))
		ss(a, b);
	else if (!ft_strncmp(line, "pa", ft_strlen(line)))
		pa(b, a);
	else if (!ft_strncmp(line, "pb", ft_strlen(line)))
		pb(a, b);
	else if (!ft_strncmp(line, "ra", ft_strlen(line)))
		ra(a);
	else if (!ft_strncmp(line, "rb", ft_strlen(line)))
		rb(b);
	else if (!ft_strncmp(line, "rr", ft_strlen(line)))
		rr(a, b);
	else if (!ft_strncmp(line, "rra", ft_strlen(line)))
		rra(a);
	else if (!ft_strncmp(line, "rrb", ft_strlen(line)))
		rrb(b);
	else if (!ft_strncmp(line, "rrr", ft_strlen(line)))
		rrr(a, b);
	else
		(ft_putendl_fd("Error", 2), exit(1));
}

static void	get_line_from_stdin(t_node **a, t_node **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		execute_instruction(line, a, b);
		free(line);
		line = get_next_line(0);
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

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		new_argc;

	b = NULL;
	if (argc < 2)
		return (1);
	argv = check_args(argc, argv, &new_argc);
	if (!argv)
		return (ft_putendl_fd("Error", 2), 1);
	if (!validate_args(new_argc, argv))
		return (ft_putendl_fd("Error", 2), 1);
	a = init_stack(new_argc, argv);
	if (argc == 2)
		free_array(argv);
	if (!a)
		return (ft_putendl_fd("Error", 2), 1);
	get_line_from_stdin(&a, &b);
	if (is_order(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
