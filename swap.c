/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:41:27 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/02/02 15:19:15 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	swap(t_stack **stack)
{
	int	tmp;

	if (*stack == NULL || (*stack)->next == NULL )
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
}

void	do_sb(t_stack **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	do_sa(t_stack **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	do_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
