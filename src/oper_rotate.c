/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:04:52 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/05 10:40:02 by tfilipe-         ###   ########.fr       */
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
/**
 * @brief Shift up all elements of stack A by 1.
 * 
 * The first element becomes the last one.
 * @param stack The stack to change.
 */
void	ra(t_node **stack)
{
	if (rotate(stack))
		ft_printf("ra\n");
}
/**
 * @brief Shift up all elements of stack B by 1.
 * 
 * The first element becomes the last one.
 * @param stack The stack to change.
 */
void	rb(t_node **stack)
{
	if (rotate(stack))
		ft_printf("rb\n");
}
/**
 * @brief Shift up all elements of stack A and B by 1.
 * 
 * The first element becomes the last one.
 * @param stack The stacks to change.
 */
void	rr(t_node **stack_a, t_node **stack_b)
{
	bool ra;
	bool rb;

	ra = rotate(stack_a);
	rb = rotate(stack_b);
	if (ra || rb)
		ft_printf("rr\n");
}