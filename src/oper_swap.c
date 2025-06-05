/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:02:57 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/05 10:44:37 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return (false);
	first = *stack;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;
	return (true);
}

/**
 * @brief Swap the first 2 elements at the top of stack A.
 * 
 * Do nothing if there is only one element or none.
 * @param stack The stack to change.
 */
void	sa(t_node **stack_a)
{
	if (swap(stack_a))
		ft_printf("sa\n");
}

/**
 * @brief Swap the first 2 elements at the top of stack B.
 * 
 * Do nothing if there is only one element or none.
 * @param stack The stack to change.
 */
void	sb(t_node **stack_b)
{
	if (swap(stack_b))
		ft_printf("sb\n");
}

/**
 * @brief Swap the first 2 elements at the top of stack A and B.
 * 
 * Do nothing if there is only one element or none.
 * @param stacks The stacks to change.
 */
void	ss(t_node **stack_a, t_node **stack_b)
{
	bool	sa;
	bool	sb;

	sa = swap(stack_a);
	sb = swap(stack_b);
	if (sa || sb)
		ft_printf("ss\n");
}
