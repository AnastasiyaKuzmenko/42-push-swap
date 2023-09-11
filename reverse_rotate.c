/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:05:05 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/03/21 16:00:12 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*seclast;

	if (find_size(*stack) > 2)
	{
		last = *stack;
		seclast = NULL;
		while (last->next)
		{
			seclast = last;
			last = last->next;
		}
		seclast->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	do_rrb(t_stack **b, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		reverse_rotate(b);
		ft_putstr_fd("rrb\n", 1);
		i++;
	}
}

void	do_rra(t_stack **a, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		reverse_rotate(a);
		ft_putstr_fd("rra\n", 1);
		i++;
	}
}

void	do_rrr(t_stack **a, t_stack **b, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		ft_putstr_fd("rrr\n", 1);
		i++;
	}
}
