/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:58:10 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/07 19:25:25 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "../includes/push_swap_bonus.h"


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

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*line;

	b = NULL;
	if (argc < 2)
		return (0);
	if (!validate_args(argc, argv))
		return (ft_putendl_fd("Error", 2), 1);
	a = init_stack(argc, argv);
	if (!a)
		return (ft_putendl_fd("Error", 2), 1);
	while ((line = get_next_line(0)))
	{
		line[ft_strlen(line) - 1] = '\0';
		execute_instruction(line, &a, &b);
		free(line);
	}
	if (is_order(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
