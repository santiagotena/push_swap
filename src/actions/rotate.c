/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:30:34 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/03 12:48:21 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * @brief Shift up all elements of stack a by 1.
The first element becomes the last one.
 * 
 * @param a_stack 
 * @param rr_call 
 */
void	ra(t_stack **a_stack, int rr_call)
{
	t_stack	*node;
	t_stack	*temp;
	int		rotate_value;
	int		index_value;

	if (!a_stack || !(*a_stack))
		return ;
	if ((*a_stack)->next == NULL)
		return ;
	rotate_value = (*a_stack)->value;
	index_value = (*a_stack)->index;
	node = ft_lstnew_mod(rotate_value, index_value);
	ft_lstadd_back_mod(a_stack, node);
	temp = (*a_stack)->next;
	free(*a_stack);
	*a_stack = temp;
	if (!rr_call)
		ft_printf("ra\n");
	return ;
}

/**
 * @brief Shift up all elements of stack b by 1. 
 * The first element becomes the last one.
 * 
 * @param b_stack 
 * @param rr_call 
 */
void	rb(t_stack **b_stack, int rr_call)
{
	t_stack	*node;
	t_stack	*temp;
	int		rotate_value;
	int		index_value;

	if (!b_stack || !(*b_stack))
		return ;
	if ((*b_stack)->next == NULL)
		return ;
	rotate_value = (*b_stack)->value;
	index_value = (*b_stack)->index;
	node = ft_lstnew_mod(rotate_value, index_value);
	ft_lstadd_back_mod(b_stack, node);
	temp = (*b_stack)->next;
	free(*b_stack);
	*b_stack = temp;
	if (!rr_call)
		ft_printf("rb\n");
	return ;
}

/**
 * @brief ra and rb at the same time.
 * 
 * @param a_stack 
 * @param b_stack 
 */
void	rr(t_stack **a_stack, t_stack **b_stack)
{
	ra(a_stack, 1);
	rb(b_stack, 1);
	ft_printf("rr\n");
	return ;
}
