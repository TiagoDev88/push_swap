/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:03:42 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 16:03:42 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool reverse(t_node **stack)
{
	t_node *last_node;
	t_node *tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (false);

	tmp = *stack;
	while(tmp->next->next)
		tmp = tmp->next;
	ft_printf("CONTEUDO DO ULTIMO NO %d\n", tmp->next->value);
	last_node = tmp->next;
	tmp->next = NULL;
	add_top(stack, last_node);
	return (true);
}

void	rra(t_node **stack)
{
	if (reverse(stack))
		ft_printf("rra\n");
}
void	rrb(t_node **stack)
{
	if (reverse(stack))
		ft_printf("rrb\n");
}
void	rrr(t_node **stack_a, t_node **stack_b)
{
	bool rra;
	bool rrb;

	rra = reverse(stack_a);
	rrb = reverse(stack_b);
	if (rra || rrb)
		ft_printf("rrr\n");
}