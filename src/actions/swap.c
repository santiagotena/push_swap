/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:30:31 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/02 23:41:37 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * @brief Swap the first 2 elements at the top of stack a. 
 * Do nothing if there is only one or no elements.
 * 
 * @param a_stack 
 */
void	sa(t_stack **a_stack)
{
	t_stack	*node;
	t_stack	*temp;
	int		swap_value;
	int		index_value;

	if (!a_stack || !(*a_stack))
		return ;
	if ((*a_stack)->next == NULL)
		return ;
	swap_value = (*a_stack)->next->value;
	index_value = (*a_stack)->next->index;
	node = ft_lstnew_mod(swap_value, index_value);
	temp = (*a_stack)->next;
	(*a_stack)->next = (*a_stack)->next->next;
	free(temp);
	ft_lstadd_front_mod(a_stack, node);
	ft_printf("sa\n");
	return ;
}

/**
 * @brief Swap the first 2 elements at the top of stack b. 
 * Do nothing if there is only one or no elements.
 * 
 * @param b_stack 
 */
void	sb(t_stack **b_stack)
{
	t_stack	*node;
	t_stack	*temp;
	int		swap_value;
	int		index_value;

	if (!b_stack || !(*b_stack))
		return ;
	if ((*b_stack)->next == NULL)
		return ;
	swap_value = (*b_stack)->next->value;
	index_value = (*b_stack)->next->index;
	node = ft_lstnew_mod(swap_value, index_value);
	temp = (*b_stack)->next;
	(*b_stack)->next = (*b_stack)->next->next;
	free(temp);
	ft_lstadd_front_mod(b_stack, node);
	ft_printf("sb\n");
	return ;
}

/**
 * @brief Do sa and sb at the same time.
 * 
 * @param a_stack 
 * @param b_stack 
 */
// void	ss(t_stack **a_stack, t_stack **b_stack)
// {
	
	
// 	return ;
// }
