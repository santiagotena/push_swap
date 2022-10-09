/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:49:40 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/08 18:52:51 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_maxind(t_stack **stack)
{
	t_stack	*node;
	int	max_a_index;

	node = *stack;
	while (node)
	{
		if (max_a_index < node->index)
			max_a_index = node->index;
		node = node->next;
	}
	return (max_a_index);
}

void	tp_high_index(t_stack **a_stack, t_stack **b_stack, int max_a_ind)
{
	t_stack	*node_a;
	t_stack	*node_b;
	t_stack	*low_ind_a_node;

	node_a = *a_stack;
	node_b = *b_stack;
	low_ind_a_node = *a_stack;
	while (node_a)
	{
		if (node_a->index < low_ind_a_node->index)
			low_ind_a_node = node_a;
		node_a = node_a->next;
	}
	while (node_b)
	{
		if (node_b->index > max_a_ind)
			node_b->target_pos = low_ind_a_node->pos;
		node_b = node_b->next;
	}
}
