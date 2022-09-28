/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:25:09 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/28 17:09:39 by stena-he         ###   ########.fr       */
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
	t_stack		*a_stack;
	t_stack		*node;
	// t_stack		*head;
	int			index;
	long int	new;
	// head = *a_stack;
	index = 1;
	new = ft_atoi_mod(argv[index]);
	a_stack = ft_lstnew_mod(new);
	// printf("%d", a_stack->value);
	index++;
	while (argv[index] != NULL)
	{
		new = ft_atoi_mod(argv[index]);
		node = ft_lstnew_mod(new);
		ft_lstadd_back_mod(&a_stack, node);
		// Free node?
		// printf("%d", a_stack->value);
		index++;
	}
	// a_stack = head;
	// printf("%d", a_stack->value);
	
	// check_dup(*argv);
	// is_sorted(&a_stack);
}

