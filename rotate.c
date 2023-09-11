/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:23:57 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/03/21 16:02:36 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (find_size(*stack) > 2)
	{
		first = *stack;
		last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		*stack = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	do_rb(t_stack **b, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		rotate(b);
		ft_putstr_fd("rb\n", 1);
		i++;
	}
}

void	do_ra(t_stack **a, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		rotate(a);
		ft_putstr_fd("ra\n", 1);
		i++;
	}
}

void	do_rr(t_stack **a, t_stack **b, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		rotate(a);
		rotate(b);
		ft_putstr_fd("rr\n", 1);
		i++;
	}
}
