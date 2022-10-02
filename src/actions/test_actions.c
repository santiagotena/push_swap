/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:20:40 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/02 23:51:09 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	test_actions(t_stack **a_stack, t_stack **b_stack)
{
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// pa(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);

	sa(a_stack, 0);
	print_stacks(a_stack, b_stack);
	pb(a_stack, b_stack);
	pb(a_stack, b_stack);
	print_stacks(a_stack, b_stack);
	sb(b_stack, 0);
	print_stacks(a_stack, b_stack);
	ss(a_stack, b_stack);
	print_stacks(a_stack, b_stack);
}

void	print_stacks(t_stack **a_stack, t_stack **b_stack)
{
	ft_printf("A Stack:\n");
	read_stack(a_stack); 
	ft_printf("\n");
	ft_printf("B Stack:\n");
	read_stack(b_stack);
	ft_printf("\n");
}

void	read_stack(t_stack **stack)
{
	t_stack	*last_node;

	last_node = *stack;
	if (*stack == NULL)
		return ;
	ft_printf("%d %d\n", last_node->value, last_node->index);
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
		ft_printf("%d %d\n", last_node->value, last_node->index);
	}
	return ;
}