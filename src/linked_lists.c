/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:27:35 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/02 22:47:43 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew_mod(int value, int index)
{
	t_stack	*output;

	output = malloc(sizeof(t_stack));
	if (!output)
		return (NULL);
	if (index)
	{
		output->value = value;
		output->index = index;
		output->next = NULL;	
	}
	else
	{
		output->value = value;
		output->next = NULL;
	}
	return (output);
}

void	ft_lstadd_back_mod(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	last_node = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new;
	return ;
}

void	ft_lstadd_front_mod(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
