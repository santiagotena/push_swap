/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:25:09 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/03 00:23:26 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *a_stack)
{
	while (a_stack->next != NULL)
	{
		if (a_stack->value > a_stack->next->value)
			return (0);
		a_stack = a_stack->next;
	}
	return (1);
}

int	check_dup(char **argv)
{
	int		i;
	int		j;
	int		counter;

	i = 1;
	j = 1;
	counter = 0;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi_mod(argv[i]) == ft_atoi_mod(argv[j]))
				counter++;
			j++;
		}
		if (counter >= 2)
			return (1);
		counter = 0;
		i++;
		j = 1;
	}
	return (0);
}

void	add_index(t_stack *stack_a, int stack_size)
{
	t_stack	*node;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		node = stack_a;
		value = -2147483648;
		highest = NULL;
		while (node)
		{
			if (node->value == -2147483648 && node->index == 0)
				node->index = 1;
			if (node->value > value && node->index == 0)
			{
				value = node->value;
				highest = node;
				node = stack_a;
			}
			else
				node = node->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

t_stack	*parse_args(char **argv)
{
	t_stack		*a_stack;
	t_stack		*node;
	int			index;
	int			new;

	index = 1;
	new = ft_atoi_mod(argv[index]);
	a_stack = ft_lstnew_mod(new, 0);
	index++;
	while (argv[index] != NULL)
	{
		new = ft_atoi_mod(argv[index]);
		node = ft_lstnew_mod(new, 0);
		ft_lstadd_back_mod(&a_stack, node);
		index++;
	}
	if (check_dup(argv))
		error_exit();
	if (is_sorted(a_stack))
		exit(0);
	add_index(a_stack, index);
	return (a_stack);
}
