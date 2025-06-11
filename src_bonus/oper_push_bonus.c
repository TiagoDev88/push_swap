/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:04:12 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/11 13:16:51 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static bool	push(t_node **from, t_node **to)
{
	t_node	*tmp;

	if (!from || !*from || !to)
		return (false);
	tmp = *from;
	*from = tmp->next;
	tmp->next = *to;
	*to = tmp;
	return (true);
}

/**
 * @brief Take the first element at the top of B
 * and put it at the top of A.
 * 
 * Do nothing if B is empty
 * @param stacks The stack FROM and TO.
 */
void	pa(t_node **from, t_node **to)
{
	push(from, to);
}

/**
 * @brief Take the first element at the top of A
 * and put it at the top of B.
 * 
 * Do nothing if A is empty
 * @param stacks The stack FROM and TO.
 */
void	pb(t_node **from, t_node **to)
{
	push(from, to);
}
