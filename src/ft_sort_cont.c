/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_cont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:28 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/10 02:40:57 by stena-he         ###   ########.fr       */
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
		node_b->cost_b = node_b->pos;
		if (node_b->pos > b_len / 2)
			node_b->cost_b = (b_len - node_b->pos) * -1;
		node_b->cost_a = node_b->target_pos;
		if (node_b->target_pos > a_len / 2)
			node_b->cost_a = (a_len - node_b->target_pos) * -1;
		node_b = node_b->next;
	}
}

void	find_tp(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		max_a_index;
	int		low_a_ind_pos;
	int		lowest_diff;
	int		diff;
	
	node_a = *a_stack;
	node_b = *b_stack;
	max_a_index = get_maxind(a_stack);
	low_a_ind_pos = get_lowind_pos(a_stack);
	lowest_diff = max_a_index - 1;
	while (node_b)
	{
		if (node_b->index > max_a_index)
			node_b->target_pos = low_a_ind_pos;
		else
		{
			lowest_diff = max_a_index;
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
		}
		node_b = node_b->next;
	}
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
