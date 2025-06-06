/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:02:05 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/04 14:55:29 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	assign_indexes(t_node *stack)
{
	t_node	*current_node;
	t_node	*others_node;
	int		index;

	if (!stack)
		return ;
	current_node = stack;
	while (current_node)
	{
		index = 0;
		others_node = stack;
		while (others_node)
		{
			if (others_node->value < current_node->value)
				index++;
			others_node = others_node->next;
		}
		current_node->index = index;
		current_node = current_node->next;
	}
}

static t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_bottom(t_node **stack, t_node *new)
{
	t_node	*temp;

	if (!stack || !new)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	add_top(t_node **stack, t_node *new)
{
	if (stack == NULL || new == NULL)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

t_node	*init_stack(int argc, char **argv)
{
	t_node	*head_node;
	t_node	*new;
	int		i;
	int		value;

	head_node = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new = new_node(value);
		if (!new)
		{
			free_stack(&head_node);
			return (NULL);
		}
		add_bottom(&head_node, new);
		i++;
	}
	assign_indexes(head_node);
	return (head_node);
}
