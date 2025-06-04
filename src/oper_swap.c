/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:02:57 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/04 11:03:37 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack)->next)
		return (false);
	first = *stack;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;
	return (true);
}

void	sa(t_node **stack_a)
{
	if (swap(stack_a))
		ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	if (swap(stack_b))
		ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	bool	sa_ok;
	bool	sb_ok;

	sa_ok = swap(stack_a);
	sb_ok = swap(stack_b);
	if (sa_ok || sb_ok)
		ft_printf("ss\n");
}
