/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:38:07 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/04/24 11:46:28 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct stack
{
	int				data;
	int				index;
	struct stack	*next;
}	t_stack;

// instruction
void	do_pb(t_stack **a, t_stack **b);
void	do_pa(t_stack **a, t_stack **b);
void	do_ss(t_stack **a, t_stack **b);
void	do_sa(t_stack **a);
void	do_sb(t_stack **b);
void	do_rb(t_stack **b, int counter);
void	do_ra(t_stack **a, int counter);
void	do_rr(t_stack **a, t_stack **b, int counter);
void	do_rrb(t_stack **b, int counter);
void	do_rra(t_stack **a, int counter);
void	do_rrr(t_stack **a, t_stack **b, int counter);

// Sorting a small set of numbers
void	sort_three(t_stack **stack);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **root, t_stack **b);

// Input validation
int		check_sort(t_stack *stack);
int		check_duplicates(int num, char **argv, int index);
int		check_digits(int argc, char **argv);
int		check_overflow(char *str);

// Function for working with linked lists
int		find_size(t_stack *stack);
void	insert_end(t_stack **a, int value);
void	free_list(t_stack **head);

// Radix sort
void	find_index(t_stack **a);
int		find_max_bits(t_stack *stack);
void	sort_radix(t_stack **a, t_stack **b);

void	sort(t_stack **a, t_stack **b);
void	free_str(char **str);

#endif
