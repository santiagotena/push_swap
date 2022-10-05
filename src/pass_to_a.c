/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:28 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/05 10:43:16 by stena-he         ###   ########.fr       */
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
	while (node_a->next != NULL)
	{
		node_a->pos = position;
		position++;
		node_a = node_a->next;
	}
	node_a->pos = position;
	position = 0;
	while (node_b->next != NULL)
	{
		node_b->pos = position;
		position++;
		node_b = node_b->next;
	}
	node_b->pos = position;
}

void	find_target_pos(t_stack **a_stack, t_stack **b_stack, int max_index)
{
	t_stack	*node_a;
	t_stack	*node_b;
	
	node_a = *a_stack;
	node_b = *b_stack;
	while (node_b->next != NULL)
	{
		if (node_b->index == max_index)
		{
			while (node_a->next != NULL)
			{
				if (node_b->index == node_a->index + 1)
					node_b->target_pos = node_a->pos + 1;
				node_a = node_a->next;
			}
			if (node_b->index == node_a->index + 1)
				node_b->target_pos = node_a->pos + 1;
			node_a = *a_stack;
			node_b = node_b->next;
			continue ;
		}
		while (node_a->next != NULL)
		{
			if (node_b->index == node_a->index - 1)
				node_b->target_pos = node_a->pos;
			node_a = node_a->next;
		}
		if (node_b->index == node_a->index - 1)
			node_b->target_pos = node_a->pos;
		node_a = *a_stack;
		node_b = node_b->next;
	}
	//Last b node
}

void	pass_to_a(t_stack **a_stack, t_stack **b_stack, int max_index)
{
	//Add loop here
	//while (b_stack != NULL)
	add_pos(a_stack, b_stack);
	find_target_pos(a_stack, b_stack, max_index);
	
}
// print_stacks(a_stack, b_stack);
// printf("%d %d %d %d\n", node->value, node->index, len, len/2);