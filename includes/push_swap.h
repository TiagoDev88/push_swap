/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:49:35 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/04 11:09:42 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../includes/libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node  *next;
}   t_node;

typedef struct s_stack {
	t_node	*top;
	int		size;
}	t_stack;

t_node	*init_stack(int argc, char **argv);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
int	validate_args(int argc, char **argv);
void free_stack(t_node **stack);
void	pb(t_node **from, t_node **to);
void	pa(t_node **from, t_node **to);
void add_bottom(t_node **stack, t_node *new);
void add_top(t_node **stack, t_node *new);
void rrr(t_node **stack_a, t_node **stack_b);
void rrb(t_node **stack);
void rra(t_node **stack);
void ra(t_node **stack);
void rb(t_node **stack);
void rr(t_node **stack_a, t_node **stack_b);
int stack_size(t_node *stack);
void sort_up_to_five(t_node **stack);

/* ************************************************************************** */


/* ****************************** func_linked_list ************************** */


/* ****************************** main ************************************** */



/* ****************************** push_swap ********************************* */


#endif