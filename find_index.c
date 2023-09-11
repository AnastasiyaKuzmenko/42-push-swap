/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:33:29 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/05/08 11:23:57 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	sort_bubble(int *array, int len_a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < len_a - 1)
	{
		j = 0;
		while (j < len_a - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	add_elements(t_stack *a, int *array)
{
	t_stack	*curr;
	int		index;

	index = 0;
	curr = a;
	while (curr)
	{
		array[index] = curr->data;
		curr = curr->next;
		index++;
	}
}

void	find_index(t_stack **a)
{
	int		*array;
	int		len_a;
	t_stack	*curr;
	int		t;

	len_a = find_size(*a);
	array = (int *)malloc(len_a * sizeof(int));
	if (NULL == array)
		return ;
	add_elements(*a, array);
	sort_bubble(array, len_a);
	curr = *a;
	while (curr)
	{
		t = 0;
		while (t < len_a && array[t] != curr->data)
			t++;
		if (curr->data == array[t])
		{
			curr->index = t;
		}
		curr = curr->next;
	}
	free(array);
}
