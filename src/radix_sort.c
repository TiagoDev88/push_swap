/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:12:26 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 14:34:39 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	max_bits;
	int	max_size;
	int	i;
	int	j;

	max_size = size - 1;
	max_bits = 0;
	while (max_size >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_b, stack_a);
		i++;
	}
}
