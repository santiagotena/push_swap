/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:45:18 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/11 22:46:28 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exec_actions(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_b;
	int		lowest_cost;
	int		cost;
	int		cost_a;
	int		cost_b;

	node_b = *b_stack;
	lowest_cost = abs_val(node_b->cost_a) + abs_val(node_b->cost_b);
	while (node_b)
	{
		cost = abs_val(node_b->cost_a) + abs_val(node_b->cost_b);
		if (cost <= lowest_cost)
		{
			cost_a = node_b->cost_a;
			cost_b = node_b->cost_b;
			lowest_cost = cost;
		}
		node_b = node_b->next;
	}
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a_stack, b_stack);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a_stack, b_stack);
		cost_a++;
		cost_b++;
	}
	if (cost_a != 0)
	{
		while (cost_a > 0)
		{
			ra(a_stack, 0);
			cost_a--;
		}
		while (cost_a < 0)
		{
			rra(a_stack, 0);
			cost_a++;
		}
	}
	if (cost_b != 0)
	{
		while (cost_b > 0)
		{
			rb(b_stack, 0);
			cost_b--;
		}
		while (cost_b < 0)
		{
			rrb(b_stack, 0);
			cost_b++;
		}
	}
}
