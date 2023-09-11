/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:20:52 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/02/02 15:18:57 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = (*dest);
	*dest = *src;
	*src = tmp;
}

void	do_pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	do_pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}
