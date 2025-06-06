/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:05:45 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 14:34:52 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_stack(t_node **stack)
{
    t_node *current;
    t_node *temp;

    if (!stack)
        return;

    current = *stack;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    *stack = NULL;
}

int	stack_size(t_node *stack)
{
	t_node	*ptr;
	int		count;

	count = 0;
	ptr = stack;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}

int is_order(t_node *stack)
{
	t_node *curr;

	curr = stack;
	while (curr->next)
	{
		if (curr->index > curr->next->index)
			return (0);
		curr = curr->next;
	}
	return (1);
}
