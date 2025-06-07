/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:49:35 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/07 20:30:13 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* ****************************** TURK SORT ********************************* */

void	push_back_to_a(t_node **a, t_node **b);
void	push_chunks(t_node **a, t_node **b, int size);

/* ****************************** INIT STACK ******************************** */

t_node	*init_stack(int argc, char **argv);
void	add_bottom(t_node **stack, t_node *new);
void	add_top(t_node **stack, t_node *new);

/* ****************************** OPER PUSH ********************************* */

void	pb(t_node **from, t_node **to);
void	pa(t_node **from, t_node **to);

/* ****************************** OPER REVERSE ****************************** */

void	rrr(t_node **stack_a, t_node **stack_b);
void	rrb(t_node **stack);
void	rra(t_node **stack);

/* ****************************** OPER ROTATE ******************************* */

void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);

/* ****************************** OPER SWAP ********************************* */

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

/* ****************************** PUSH SWAP ********************************* */

void	push_swap(t_node **stack_a, t_node **stack_b);
int		find_index(t_node *stack, int index);

/* ****************************** RADIX SORT ******************************** */

void	radix_sort(t_node **stack_a, t_node **stack_b, int size);

/* ****************************** UTILS STACK ******************************* */

void	free_stack(t_node **stack);
int		stack_size(t_node *stack);
int		is_order(t_node *stack);

/* ****************************** VALIDATE ARGS ***************************** */

int		validate_args(int argc, char **argv);

/* ************************************************************************** */

#endif