/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:13:43 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/05/02 10:34:22 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	check_sort(t_stack *stack)
{
	t_stack	*curr;

	curr = stack;
	if (NULL == curr)
	{
		return (0);
	}
	while (curr->next)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	check_duplicates(int num, char **argv, int index)
{
	index++;
	while (argv[index])
	{
		if (ft_atoi(argv[index]) == num)
			return (1);
		index++;
	}
	return (0);
}

int	check_overflow(char *str)
{
	int	number;

	number = ft_atoi(str);
	if (str[0] == '-')
	{
		if (number > 0)
		{
			return (1);
		}
	}
	if (str[0] != '-')
	{
		if (number < 0)
		{
			return (1);
		}
	}
	return (0);
}

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
		{
			if (ft_isdigit(argv[i][1]) && argv[i][1] != '\0')
				j++;
			else
				return (0);
		}
		while (argv[i][j] && ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] != '\0' || check_overflow(argv[i])
			|| ft_strlen(argv[i]) > 11)
			return (0);
		i++;
	}
	return (1);
}
