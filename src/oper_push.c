/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:04:12 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 16:04:12 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool push(t_stack *from, t_stack *to)
{
	t_node *tmp;

	if (!from || from->size == 0)
		return (false);

	tmp = from->top;
	from->top = tmp->next;
	from->size--;
	
	tmp->next = to->top;
	to->top = tmp;
	to->size++;
	return (true);
}

void	pa(t_stack *from, t_stack *to)
{
	if (push(from, to))
		ft_printf("pa\n");
}

void	pb(t_stack *from, t_stack *to)
{
	if (push(from, to))
		ft_printf("pb\n");
}
