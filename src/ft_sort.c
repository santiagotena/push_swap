/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:45:12 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/03 15:14:12 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		ft_sort(t_stack **a_stack, t_stack **b_stack)
{
	int a_stack_len;

	b_stack = NULL; //Delete
	a_stack_len = ft_lst_len(a_stack);
	if (a_stack_len == 2)
		sa(a_stack, 0);
}