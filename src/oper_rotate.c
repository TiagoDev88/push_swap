/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:04:52 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 16:04:52 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool rotate(t_node **stack)
{
	t_node *first;
	t_node *second;

	if (!stack || !(*stack) || !(*stack)->next)
		return (false);

	first = *stack;
	second = first->next;
	first->next = NULL;
	*stack = second;
	add_bottom(stack, first);
	return (true);
}

void	ra(t_node **stack)
{
	if (rotate(stack))
		ft_printf("ra\n");
}

void	rb(t_node **stack)
{
	if (rotate(stack))
		ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	bool ra;
	bool rb;

	ra = rotate(stack_a);
	rb = rotate(stack_b);
	if (ra || rb)
		ft_printf("rr\n");
}