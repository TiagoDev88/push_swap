/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:36:32 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/05 16:20:26 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	index_min(t_node *stack)
// {
// 	int min;
// 	int index;
// 	t_node	*current_node;
// 	t_node	*others_node;

// 	current_node = stack;

// 	index = 0;
// 	min = current_node->index;
// 	while (current_node)
// 	{
// 		others_node = stack->next;
// 		while(others_node)
// 		{
// 			if (others_node->index < current_node->index)
// 				index++;
// 			others_node = others_node->next;
// 		}
// 		min = index;
// 		current_node = current_node->next;
// 	}
// 	return (min);
// }


int	index_min(t_node *stack)
{
	int min;
	int min_index;
	int i;
	t_node *curr;

	curr = stack->next;

	min_index = 0;
	min = stack->index;
	i = 1;
	while (curr)
	{
		if (min > curr->index)
		{
			min = curr->index;
			min_index = i;
		}
		i++;
		curr = curr->next;
	}
	return (min_index);
}

void	sort_to_five(t_node **stack_a, t_node **stack_b)
{
	int size;
	int sizeb;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_three(stack_a);

	//agora vou ter que encontrar o melhor intervalo para puxar do b para a
	// A, e puxar o min para cima em A. Quando tiverem todos.
	//fazer um loop 
	size = index_min(*stack_a);
	//sizeb = index_min(*stack_b);
	ft_printf("MIN A %d\n", size);
	//ft_printf("MIN B %d\n", sizeb);
}

void	sort_three(t_node **stack)
{
	int first;
	int second;
	int three;

	first = (*stack)->index;
	second = (*stack)->next->index;
	three = (*stack)->next->next->index;

	if (first > second && second < three && first < three)
		sa(stack);
	else if (first > second && second < three && first > three)
		ra(stack);
	else if (first > second && second > three)
		{
			sa(stack);
			rra(stack);
		}
	else if (first < second && second > three && first > three)
			rra(stack);
	else if (first < second && second > three)
	{
		rra(stack);
		sa(stack);
	}
}

void push_swap(t_node **stack_a, t_node **stack_b)
{
	int size;
	int size1;
	size = stack_size(*stack_a);
	size1 = stack_size(*stack_b);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size > 3 && size < 6)
		sort_to_five(stack_a, stack_b);
	ft_printf("func push_swap SIZE: %d\n", size1);
}
