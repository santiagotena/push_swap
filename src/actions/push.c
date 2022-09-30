/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:30:29 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/30 20:25:46 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * @brief Take the first element at the top of stack B and put it at 
 * the top of stack A. Do nothing if B is empty.
 * 
 * @param a_stack 
 * @param b_stack 
 */
void	pa(t_stack **a_stack, t_stack **b_stack)
{
	int		push_value;
	int		tmp;
	
	if (!b_stack || !(*b_stack))
		return ;
	push_value = (*b_stack)->value;
	
	
	
	return ;
}

/**
 * @brief Take the first element at the top of A and put it at 
 * the top of B. Do nothing if A is empty.
 * 
 * @param a_stack 
 * @param b_stack 
 */
void	pb(t_stack **a_stack, t_stack **b_stack)
{
	if (!a_stack || !(*a_stack))
		return ;
	
	return ;
}