/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:28 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/05 19:17:54 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_pos(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		position;
	
	node_a = *a_stack;
	node_b = *b_stack;
	position = 0;
	while (node_a)
	{
		node_a->pos = position;
		position++;
		node_a = node_a->next;
	}
	position = 0;
	while (node_b)
	{
		node_b->pos = position;
		position++;
		node_b = node_b->next;
	}
}

void	find_target_pos(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		max_a_index;
	int		min_a_index;
	
	node_a = *a_stack;
	node_b = *b_stack;
	max_a_index = 0;
	while (node_a)
	{
		if (max_a_index < node_a->index)
			max_a_index = node_a->index;
		node_a = node_a->next;
	}
	node_a = *a_stack;
	min_a_index = max_a_index;
	while (node_a)
	{
		if (min_a_index > node_a->index)
			min_a_index = node_a->index;
		node_a = node_a->next;
	}
	node_a = *a_stack;



}

void	pass_to_a(t_stack **a_stack, t_stack **b_stack)
{
	//Add loop here
	//while (b_stack)
	add_pos(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	find_target_pos(a_stack, b_stack);
}
// print_stacks(a_stack, b_stack);
// printf("%d %d %d %d\n", node->value, node->index, len, len/2);