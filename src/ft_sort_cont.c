/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_cont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:28 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/07 12:09:22 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calc_cost(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		len_a;
	int		len_b;

	node_a = *a_stack;
	node_b = *b_stack;
	len_a = ft_lst_len(a_stack);
	len_b = ft_lst_len(b_stack);
		
}

void	find_tp_cont(t_stack **a_stack, t_stack **b_stack,
			int max_a_index, int min_a_index)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		lowest_diff;
	int		diff;

	node_a = *a_stack;
	node_b = *b_stack;
	tp_high_index(b_stack, node_b, max_a_index, min_a_index);
	while (node_b)
	{
		lowest_diff = max_a_index - 1;
		while (node_a)
		{
			diff = node_a->index - node_b->index;
			if (diff > 0 && diff < lowest_diff)
			{
				lowest_diff = diff;
				node_b->target_pos = node_a->pos;
			}
			node_a = node_a->next;
		}
		node_a = *a_stack;
		node_b = node_b->next;
	}
	node_b = *b_stack;
}

void	find_tp(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		max_a_index;
	int		min_a_index;

	node_a = *a_stack;
	node_b = *b_stack;
	max_a_index = get_maxind(a_stack, node_a);
	min_a_index = get_minind(a_stack, node_a, max_a_index);
	find_tp_cont(a_stack, b_stack, max_a_index, min_a_index);
}

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
