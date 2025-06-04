/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:36:32 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/04 22:36:32 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void	sort_up_to_five(t_node **stack)
{
	int size;

	size = stack_size(*stack);

	if (size == 2)
		sa(stack);
	else if (size == 3)
	{
		if ((*stack)->index > (*stack)->next->index && (*stack)->index < 
				(*stack)->next->next->index)
			sa(stack);
		else if ((*stack)->index < (*stack)->next->index && (*stack)->index > 
				(*stack)->next->next->index)
			rra(stack);
		else if ((*stack)->index > (*stack)->next->index && (*stack)->index > 
				(*stack)->next->next->index)
			{
				rra(stack);
				rra(stack);
			}
	}
}