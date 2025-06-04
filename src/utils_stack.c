/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:05:45 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/04 11:01:06 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//funções da linked list (stack)

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
