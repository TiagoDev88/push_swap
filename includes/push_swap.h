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

t_stack *init_stack(int argc, char **argv);
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
int	validate_args(int argc, char **argv);
void free_stack(t_stack *stack);

/* ************************************************************************** */


/* ****************************** func_linked_list ************************** */


/* ****************************** main ************************************** */



/* ****************************** push_swap ********************************* */


#endif