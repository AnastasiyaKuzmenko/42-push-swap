/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:12 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/03/21 11:23:33 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	find_max_bits(t_stack *stack)
{
	t_stack	*curr;
	int		max;
	int		max_bits;

	curr = stack;
	max_bits = 0;
	max = curr->index;
	while (curr)
	{
		if (curr->index > max)
		{
			max = curr->index;
		}
		curr = curr->next;
	}
	while ((max >> max_bits) != 0)
	{
		max_bits++;
	}
	return (max_bits);
}

void	sort_radix(t_stack **a, t_stack **b)
{
	int		i;
	int		j;
	int		max_bits;
	int		size_a;
	t_stack	*head;

	i = 0;
	size_a = find_size(*a);
	max_bits = find_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size_a)
		{
			head = *a;
			if (((head->index >> i) & 1) == 1)
				do_ra(a, 1);
			else
				do_pb(a, b);
			j++;
		}
		while (find_size(*b) != 0)
			do_pa(a, b);
		i++;
	}
}
