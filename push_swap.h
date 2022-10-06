/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:13:41 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/06 19:01:10 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Libraries */
//Std libraries
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//Custom libraries
# include "libraries/ft_printf/libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"

/* Structs */
//Stacks 
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/* Functions */
// Actions //
//Push
void		pa(t_stack **a_stack, t_stack **b_stack);
void		pb(t_stack **a_stack, t_stack **b_stack);
//Swap
void		sa(t_stack **a_stack, int ss_call);
void		sb(t_stack **b_stack, int ss_call);
void		ss(t_stack **a_stack, t_stack **b_stack);
//Rotate
void		ra(t_stack **a_stack, int rr_call);
void		rb(t_stack **b_stack, int rr_call);
void		rr(t_stack **a_stack, t_stack **b_stack);
//Reverse rotate
void		rra(t_stack **a_stack, int rrr_call);
void		rrb(t_stack **b_stack, int rrr_call);
void		rrr(t_stack **a_stack, t_stack **b_stack);

// Test actions //
void		test_actions(t_stack **a_stack, t_stack **b_stack); //Delete
void		read_stack(t_stack **stack);
void		print_stacks(t_stack **a_stack, t_stack **b_stack);//Delete//

// Sort //
void		ft_sort(t_stack **a_stack, t_stack **b_stack);
void		pass_to_a(t_stack **a_stack, t_stack **b_stack);

// Sort utils
int			get_maxind(t_stack **stack, t_stack *node);
int			get_minind(t_stack **stack, t_stack *node, int max_a_index);
void		tp_high_index(t_stack **b_stack, t_stack *node_b,
				int max_a_index, int min_a_index);

// Parse arguments //
t_stack		*parse_args(char **argv);

// Linked lists //
int			ft_lst_len(t_stack **lst);
t_stack		*ft_lstnew_mod(int value, int index);
t_stack		*add_lsvalues(t_stack **stack);
void		ft_lstadd_back_mod(t_stack **lst, t_stack *new);
void		ft_lstadd_front_mod(t_stack **lst, t_stack *new);
void		free_stack(t_stack **stack);

// Utils //
int			ft_atoi_mod(const char *str);
void		error_exit(void);

#endif
