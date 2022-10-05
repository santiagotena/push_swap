/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:12:33 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/05 15:31:22 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a_stack;
	t_stack		*b_stack;

	b_stack = NULL;
	if (argc < 2)
		return (0);
	a_stack = parse_args(argv);

	ft_printf("Start:\n");//Delete
	print_stacks(&a_stack, &b_stack);
	// ft_printf("Actions:\n");
	// test_actions(&a_stack, &b_stack);//Delete //

	ft_sort(&a_stack, &b_stack);

	ft_printf("End:\n");//Delete
	print_stacks(&a_stack, &b_stack);//Delete //

	free_stack(&a_stack);
	free_stack(&b_stack);
	return (0);
}
