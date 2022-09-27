/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:25:09 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/28 00:55:17 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parse_args(char **argv)
{
	t_stack		a_stack;
	int			index;

	index = 1;
	while (argv[index] != NULL)
	{
		a_stack.value = ft_atoi_mod(argv[index]);
		index++;
	}
}
