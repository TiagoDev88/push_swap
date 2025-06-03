/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:02:05 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 16:02:05 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	assign_indexes(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		index = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
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

static void	add_bottom(t_stack *stack, t_node *new)
{
	t_node	*temp;

	if (!stack || !new)
		return ;
	if (!stack->top)
		stack->top = new;
	else
	{
		temp = stack->top;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	stack->size++;
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		value;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		add_bottom(stack, new_node(value));
		i++;
	}
	assign_indexes(stack);
	return (stack);
}
