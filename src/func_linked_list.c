/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:54:48 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 12:46:28 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*new_element;

	new_element = malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->value = value;
	new_element->next = NULL;
	return (new_element);
}

void	add_top(t_stack **stack, t_stack *new)
{
	t_list	*ptr;

	if (stack == NULL || new == NULL)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
	{
		ptr = *stack;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

int	size_stack(t_stack *stack)
{
	t_stack	*ptr;
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

void	free_stack(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	ptr = *stack;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	*stack = NULL;
}
