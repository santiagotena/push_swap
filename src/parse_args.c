/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:25:09 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/28 03:54:38 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	is_sorted(t_stack *a_stack)
// {
// 	while (a_stack->next != NULL)
// 	{
// 		if (a_stack->value > a_stack->next->value)
// 			break ;
// 		a_stack = a_stack->next;
// 	}
// 	exit (0);
// }

// void	check_dup(char *argv)
// {
// 	int		counter;
// 	char	test;
// 	char	current;

// 	counter = 0;
// 	test = *argv;
// 	current = *argv;
// 	while (test)
// 	{
// 		while (current)
// 		{
// 			if ( ft_atoi_mod(argv) == ft_atoi_mod(argv))
// 				counter++;
// 			current++;
// 		}
// 		if (counter >= 2)
// 			error_exit();
// 		counter = 0;
// 		test++;
// 		current = *argv;
// 	}
// 	return ;
// }

void	parse_args(char **argv)
{
	t_stack		a_stack;
	t_stack		head;
	int			index;

	a_stack.value = 0;
	head = a_stack;
	index = 1;
	while (argv[index] != NULL)
	{
		a_stack.value = ft_atoi_mod(argv[index]);
		printf("%d", a_stack.value);
		index++;
		a_stack = *a_stack.next;
	}
	a_stack = head;
	printf("%d", a_stack.value);
	
	// check_dup(*argv);
	// is_sorted(&a_stack);
}

