/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:45:12 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/04 23:21:21 by stena-he         ###   ########.fr       */
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

void	sort_more(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node;
	t_stack	*next_node;
	int		elements;
	int		len;

	node = *a_stack;
	elements = ft_lst_len(a_stack);
	len = elements;
	while (elements > 0)
	{
		next_node = node->next;
		if (node->index < len / 2)
			pb(a_stack, b_stack);
		else
			ra(a_stack, 0);
		node = next_node;
		elements--;
	}
	node = *a_stack;
	elements = ft_lst_len(a_stack);
	while (elements > 3)
	{
		pb(a_stack, b_stack);
		elements--;
	}
	sort_three(a_stack);
}

// print_stacks(a_stack, b_stack);
// printf("%d %d %d %d\n", node->value, node->index, len, len/2);

// First, we can push all of the smaller values. So, if an element has a smaller 
// index than the middle index of all the elements (the total number of values to sort divided by 2), 
// we can push it to stack B. Otherwise, we rotate A. After that, we can freely pb all the rest of the 
// elements except for the last three that will remain in stack A.

void	ft_sort(t_stack **a_stack, t_stack **b_stack)
{
	int		a_stack_len;

	a_stack_len = ft_lst_len(a_stack);
	if (a_stack_len == 2)
		sa(a_stack, 0);
	if (a_stack_len == 3)
		sort_three(a_stack);
	sort_more(a_stack, b_stack);
}
