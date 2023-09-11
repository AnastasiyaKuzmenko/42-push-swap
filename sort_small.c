/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:04:29 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/03/21 16:11:20 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	find_max(t_stack *stack)
{
	int	max;

	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
		}
		stack = stack->next;
	}
	return (max);
}

static int	find_min(t_stack *stack)
{
	int	min;

	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
		}
		stack = stack->next;
	}
	return (min);
}

void	sort_three(t_stack **stack)
{
	int	max;

	max = find_max(*stack);
	if ((*stack)->data == max)
	{
		do_ra(stack, 1);
	}
	else if ((*stack)->next->data == max)
	{
		do_rra(stack, 1);
	}
	if ((*stack)->data > (*stack)->next->data)
	{
		do_sa(stack);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	int		i;
	int		min;

	curr = *a;
	min = find_min(curr);
	i = 0;
	while (curr->data != min && ++i)
	{
		curr = curr->next;
	}
	if (i != 0)
	{
		if (i >= 2)
		{
			do_rra(a, 4 - i);
		}
		else
		{
			do_ra(a, 1);
		}
	}
	do_pb(a, b);
	sort_three(a);
	do_pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	int		i;
	int		min;

	curr = *a;
	min = find_min(curr);
	i = 0;
	while (curr->data != min && ++i)
	{
		curr = curr->next;
	}
	if (i != 0)
	{
		if (i >= 3)
		{
			do_rra(a, 5 - i);
		}
		else
		{
			do_ra(a, i);
		}
	}
	do_pb(a, b);
	sort_four(a, b);
	do_pa(a, b);
}
