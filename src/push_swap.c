/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:36:32 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 12:01:58 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	index_min(t_node *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static void	move_to_top(t_node **stack, int pos)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(stack);
			pos++;
		}
	}
}

static void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	three;

	first = (*stack)->index;
	second = (*stack)->next->index;
	three = (*stack)->next->next->index;
	if (first > second && second < three && first < three)
		sa(stack);
	else if (first > second && second < three && first > three)
		ra(stack);
	else if (first > second && second > three)
	{
		sa(stack);
		rra(stack);
	}
	else if (first < second && second > three && first > three)
		rra(stack);
	else if (first < second && second > three)
	{
		rra(stack);
		sa(stack);
	}
}

static void	sort_to_five(t_node **stack_a, t_node **stack_b, int size)
{
	int	pos;

	if (size == 4)
	{
		pos = index_min(*stack_a, 0);
		move_to_top(stack_a, pos);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_b, stack_a);
	}
	else
	{
		pos = index_min(*stack_a, 0);
		move_to_top(stack_a, pos);
		pb(stack_a, stack_b);
		pos = index_min(*stack_a, 1);
		move_to_top(stack_a, pos);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_b, stack_a);
		pa(stack_b, stack_a);
	}
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size > 3 && size < 6)
		sort_to_five(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b, size);
}
