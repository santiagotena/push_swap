/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:45:12 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/03 15:37:37 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a_stack)
{
	t_stack	*node;

	node = *a_stack;
	if (node->index > node->next->index && 
		node->index > node->next->next->index)
		ra(a_stack, 0);
	else if (node->next->index > node->index && 
		node->next->index > node->next->next->index)
		rra(a_stack, 0);
	node = *a_stack;
	if (node->index > node->next->index)
		sa(a_stack, 0);
}

void	ft_sort(t_stack **a_stack, t_stack **b_stack)
{
	int a_stack_len;

	b_stack = NULL; //Delete
	a_stack_len = ft_lst_len(a_stack);
	if (a_stack_len == 2)
		sa(a_stack, 0);
	if (a_stack_len == 3)
		sort_three(a_stack);
}