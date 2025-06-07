/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:41:40 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/07 20:46:31 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/push_swap.h"

void	push_chunks(t_node **a, t_node **b, int size)
{
	int	i;
	int	chunk_size;

	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

static int	get_max_index(t_node *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	push_back_to_a(t_node **a, t_node **b)
{
	int	pos;
	int	max;

	while (*b)
	{
		max = get_max_index(*b);
		pos = find_index(*b, max);
		if (pos <= stack_size(*b) / 2)
		{
			while (pos > 0)
			{
				rb(b);
				pos--;
			}
		}
		else
		{
			while (pos < stack_size(*b))
			{
				rrb(b);
				pos++;
			}
		}
		pa(b, a);
	}
}
