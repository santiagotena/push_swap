/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:12:33 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/12 00:15:19 by stena-he         ###   ########.fr       */
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
	ft_sort(&a_stack, &b_stack);
	free_stack(&a_stack);
	free_stack(&b_stack);
	return (0);
}
