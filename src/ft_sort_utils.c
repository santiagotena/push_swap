/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_to_a_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:49:40 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/06 19:01:16 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_maxind(t_stack **stack, t_stack *node)
{
	int	max_a_index;

	while (node)
	{
		if (max_a_index < node->index)
			max_a_index = node->index;
		node = node->next;
	}
	node = *stack;
	return (max_a_index);
}

int	get_minind(t_stack **stack, t_stack *node, int max_a_index)
{
	int	min_a_index;

	min_a_index = max_a_index;
	while (node)
	{
		if (min_a_index > node->index)
			min_a_index = node->index;
		node = node->next;
	}
	node = *stack;
	return (min_a_index);
}

void	tp_high_index(t_stack **b_stack, t_stack *node_b,
			int max_a_index, int min_a_index)
{
	while (node_b)
	{
		if (node_b->index > max_a_index)
			node_b->target_pos = min_a_index;
		node_b = node_b->next;
	}
	node_b = *b_stack;
}
