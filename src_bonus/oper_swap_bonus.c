/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:02:57 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/07 19:26:06 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/push_swap_bonus.h"

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
	swap(stack_a);
}

/**
 * @brief Swap the first 2 elements at the top of stack B.
 * 
 * Do nothing if there is only one element or none.
 * @param stack The stack to change.
 */
void	sb(t_node **stack_b)
{
	swap(stack_b);
}

/**
 * @brief Swap the first 2 elements at the top of stack A and B.
 * 
 * Do nothing if there is only one element or none.
 * @param stacks The stacks to change.
 */
void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
