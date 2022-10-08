/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_cont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:28 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/08 04:55:25 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	final_sort(t_stack **a_stack)
{
	t_stack	*node_a;
	int		lowest_pos;
	int		stack_size;

	node_a = *a_stack;
	stack_size = ft_lst_len(a_stack);
	lowest_pos = 0;
	while (node_a)
	{
		if (node_a->index == 1)
			break ;
		lowest_pos++;
		node_a = node_a->next;
	}
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(a_stack, 0);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(a_stack, 0);
			lowest_pos--;
		}
	}
}

void	exec_act(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_b;
	t_stack	*lowest_node;
	int		lowest_cost;
	int		cost;
	
	node_b = *b_stack;
	lowest_node = *b_stack;
	lowest_cost = abs_val(node_b->cost_a) + abs_val(node_b->cost_b);
	if (node_b->next == NULL)
		node_b->cost_b = 0;
	while (node_b)
	{
		cost = abs_val(node_b->cost_a) + abs_val(node_b->cost_b);
		if (cost < lowest_cost)
		{
			lowest_cost = cost;
			lowest_node = node_b;
		}
		node_b = node_b->next;
	}
	while (lowest_node->cost_a != 0 || lowest_node->cost_b != 0)
	{
		if (lowest_node->cost_a > 0 && lowest_node->cost_b > 0)
		{
			rr(a_stack, b_stack);
			lowest_node->cost_a--;
			lowest_node->cost_b--;
		}
		else if (lowest_node->cost_a < 0 && lowest_node->cost_b < 0)
		{
			rrr(a_stack, b_stack);
			lowest_node->cost_a++;
			lowest_node->cost_b++;
		}
		else
		{
			if (lowest_node->cost_a > 0)
			{
				ra(a_stack, 0);
				lowest_node->cost_a--;
			}
			if (lowest_node->cost_b > 0)
			{
				rb(b_stack, 0);
				lowest_node->cost_b--;
			}
			if (lowest_node->cost_a < 0)
			{
				rra(a_stack, 0);
				lowest_node->cost_a++;
			}
			if (lowest_node->cost_b < 0)
			{
				rrb(b_stack, 0);
				lowest_node->cost_b++;
			}
		}
		
	}
}

void	calc_cost(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		a_len;
	int		b_len;

	node_a = *a_stack;
	node_b = *b_stack;
	a_len = ft_lst_len(a_stack);
	b_len = ft_lst_len(b_stack);
	while (node_b)
	{
		if (node_b->pos + 1 < b_len/2)
			node_b->cost_b = node_b->pos;
		else
			node_b->cost_b = ((b_len - 1) - node_b->pos + 1) * -1;
		node_b = node_b->next;
	}
	node_b = *b_stack;
	while (node_b)
	{
		while (node_a)
		{
			if (node_b->target_pos == node_a->pos)
			{
				if (node_a->pos + 1 < a_len/2)
					node_b->cost_a = node_a->pos;
				else
					node_b->cost_a = ((a_len - 1) - node_a->pos + 1) * -1;
			}
			node_a = node_a->next;
		}
		node_a = *a_stack;
		node_b = node_b->next;
	}
	node_b = *b_stack;
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
