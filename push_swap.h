/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:13:41 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/28 17:07:02 by stena-he         ###   ########.fr       */
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
void		pa(void);
void		pb(void);
//Swap
void		sa(void);
void		sb(void);
void		ss(void);
//Rotate
void		ra(void);
void		rb(void);
void		rr(void);
//Reverse rotate
void		rra(void);
void		rrb(void);
void		rrr(void);

// Parse Arguments //
void		parse_args(char **argv);

// Linked lists
t_stack		*ft_lstnew_mod(int value);
void		ft_lstadd_back_mod(t_stack **lst, t_stack *new);
void		ft_lstdelone_mod(t_stack *lst, void (*del)(void *));
void		ft_lstclear_mod(t_stack **lst, void (*del)(void *));

// Utils //
int			ft_atoi_mod(const char *str);
void		error_exit(void);

#endif
