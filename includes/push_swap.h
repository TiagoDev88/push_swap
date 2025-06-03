/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:49:35 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 13:50:29 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../includes/libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				size;
	struct s_stack *next;
} t_stack;

/* ****************************** func_linked_list ************************** */
void free_stack(t_stack **stack);
int size_stack(t_stack *stack);
void add_top(t_stack **stack, t_stack *new);
t_stack *new_node(int value);

/* ****************************** main ************************************** */



/* ****************************** push_swap ********************************* */


#endif