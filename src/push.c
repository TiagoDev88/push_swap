/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:48:41 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 13:57:00 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	t_stack *tmp;
	t_stack *first;
	t_stack *second;

	if (stack->size < 2)
		return ;
	if (stack == NULL || stack == NULL)
		return ;
	tmp = stack;

	first = stack->next;
	second = stack;

}