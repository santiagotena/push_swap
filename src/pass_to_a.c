/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:28 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/05 09:40:30 by stena-he         ###   ########.fr       */
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
	node_a->pos = position;
	position++;
	while (node_a->next != NULL)
	{
		node_a = node_a->next;
		node_a->pos = position;
		position++;
	}
	position = 0;
	node_b->pos = position;
	position++;
	while (node_b->next != NULL)
	{
		node_b = node_b->next;
		node_b->pos = position;
		position++;
	}
}

void	pass_to_a(t_stack **a_stack, t_stack **b_stack)
{
	//Add loop here
	//while (b_stack != NULL)
	add_pos(a_stack, b_stack);
	
}
// print_stacks(a_stack, b_stack);
// printf("%d %d %d %d\n", node->value, node->index, len, len/2);