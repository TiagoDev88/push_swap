/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:04:12 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/04 11:06:01 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool push(t_node **from, t_node **to)
{
	t_node *tmp;

	if (!from || !*from || !to)
		return (false);

	tmp = *from;
	*from = tmp->next;
	
	tmp->next = *to;
	*to = tmp;
	return (true);
}

void	pa(t_node **from, t_node **to)
{
	if (push(from, to))
		ft_printf("pa\n");
}

void	pb(t_node **from, t_node **to)
{
	if (push(from, to))
		ft_printf("pb\n");
}
