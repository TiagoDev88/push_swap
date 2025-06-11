/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_reverse_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:03:42 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/11 13:16:52 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static bool	reverse(t_node **stack)
{
	t_node	*last_node;
	t_node	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = NULL;
	add_top(stack, last_node);
	return (true);
}

/**
 * @brief Shift down all elements of stack A by 1.
 * 
 * The last element becomes the first one.
 * @param stack The stack to change.
 */
void	rra(t_node **stack)
{
	reverse(stack);
}

/**
 * @brief Shift down all elements of stack B by 1.
 * 
 * The last element becomes the first one.
 * @param stack The stack to change.
 */
void	rrb(t_node **stack)
{
	reverse(stack);
}

/**
 * @brief Shift down all elements of stack A and B by 1.
 * 
 * The last element becomes the first one.
 * @param stack The stacks to change.
 */
void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
}
