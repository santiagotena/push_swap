/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:45:12 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/10 01:32:20 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a_stack)
{
	t_stack	*node;

	node = *a_stack;
	if (node->index > node->next->index
		&& node->index > node->next->next->index)
		ra(a_stack, 0);
	else if (node->next->index > node->index
		&& node->next->index > node->next->next->index)
		rra(a_stack, 0);
	node = *a_stack;
	if (node->index > node->next->index)
		sa(a_stack, 0);
}

void	pass_to_b(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node;
	int		elements;

	node = *a_stack;
	elements = ft_lst_len(a_stack);
	while (elements > 0)
	{
		if (node->index < elements / 2)
			pb(a_stack, b_stack);
		else
			ra(a_stack, 0);
		elements--;
	}
	elements = ft_lst_len(a_stack);
	while (elements > 3)
	{
		pb(a_stack, b_stack);
		elements--;
	}
}

void	sort_more(t_stack **a_stack, t_stack **b_stack)
{
	pass_to_b(a_stack, b_stack);
	sort_three(a_stack);
	
	while (*b_stack)
	{
		add_pos(a_stack, b_stack);
		find_tp(a_stack, b_stack);
		calc_cost(a_stack, b_stack);
		exec_act(a_stack, b_stack);
		pa(a_stack, b_stack);
	}
	
	final_sort(a_stack);

	// int counter = 2;
	// while (counter)
	// {
	// 	add_pos(a_stack, b_stack);
	// 	find_tp(a_stack, b_stack);
	// 	calc_cost(a_stack, b_stack);
	// 	print_stacks(a_stack, b_stack);//Delete //
	// 	exec_act(a_stack, b_stack);
	// 	pa(a_stack, b_stack);
	// 	print_stacks(a_stack, b_stack);//Delete //
		
	// 	counter --;
	// }
}

void	ft_sort(t_stack **a_stack, t_stack **b_stack)
{
	int		a_stack_len;

	a_stack_len = ft_lst_len(a_stack);
	if (a_stack_len == 2)
	{
		sa(a_stack, 0);
		return ;
	}
	if (a_stack_len == 3)
	{
		sort_three(a_stack);
		return ;
	}	
	sort_more(a_stack, b_stack);
}
