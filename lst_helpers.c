/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:46:49 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/04/26 17:33:53 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	find_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_list(t_stack **list)
{
	t_stack	*curr;
	t_stack	*next;

	curr = *list;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*list = NULL;
}

void	insert_end(t_stack **a, int value)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = malloc(sizeof(t_stack));
	if (NULL == new_node)
	{
		return ;
	}
	new_node->data = value;
	new_node->next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	curr = *a;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}
