/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:27:35 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/28 12:51:14 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew_mod(void *value)
{
	t_stack	*output;

	output = malloc(sizeof(t_stack));
	if (!output)
		return (NULL);
	output->value = value;
	output->next = NULL;
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

void	ft_lstdelone_mod(t_stack *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->value);
	free(lst);
}

void	ft_lstclear_mod(t_stack **lst, void (*del)(void *))
{
	t_stack	*temporary;
	t_stack	*prev;

	temporary = *lst;
	prev = NULL;
	while (temporary != NULL)
	{		
		del(temporary->value);
		prev = temporary;
		temporary = temporary->next;
		free(prev);
	}
	*lst = NULL;
}