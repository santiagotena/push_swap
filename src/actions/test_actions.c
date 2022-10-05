/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:20:40 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/05 16:17:40 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	test_actions(t_stack **a_stack, t_stack **b_stack)
{
	//Push
	
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// pa(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);

	// //Swap
	
	// sa(a_stack, 0);
	// print_stacks(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// sb(b_stack, 0);
	// print_stacks(a_stack, b_stack);
	// ss(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);

	// pb(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// sb(b_stack, 0);
	// print_stacks(a_stack, b_stack);
	// ss(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);

	// //Rotate
	
	// ra(a_stack, 0);
	// print_stacks(a_stack, b_stack);

	// pb(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// rb(b_stack, 0);
	// ra(a_stack, 0);
	// print_stacks(a_stack, b_stack);

	// pb(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// rr(a_stack, b_stack);
	// rr(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);

	// //Rev rotate

	// rra(a_stack, 0);
	// print_stacks(a_stack, b_stack);

	// pb(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// rrb(b_stack, 0);
	// rra(a_stack, 0);
	// print_stacks(a_stack, b_stack);

	// pb(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// pb(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
	// rrr(a_stack, b_stack);
	// rrr(a_stack, b_stack);
	// print_stacks(a_stack, b_stack);
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
	t_stack	*node;
	node = *stack;
	
	if (*stack == NULL)
		return ;
		ft_printf("val ind pos tp ca cb\n");
	while (node)
	{
		printf("%i   %i   %i   %i   %i   %i\n", node->value, node->index, node->pos, node->target_pos, node->cost_a, node->cost_b);		
		node = node->next;
	}
	return ;
}
