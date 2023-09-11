/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:19:10 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/04/26 17:34:00 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sort(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = find_size(*a);
	if (size_a == 0)
		return ;
	if (size_a == 2)
		do_sa(a);
	else if (size_a == 3)
		sort_three(a);
	else if (size_a == 4)
		sort_four(a, b);
	else if (size_a == 5)
		sort_five(a, b);
	else
	{
		find_index(a);
		sort_radix(a, b);
	}
}

void	free_str(char **str)
{
	int	index;

	index = 0;
	if (str == NULL)
		return ;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
}

static int	init_stack(int argc, char **argv, t_stack **a, int index)
{
	char	**arg;

	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		index = 1;
		arg = argv;
	}
	while (arg[index])
	{
		if (check_digits(argc, arg)
			&& !check_duplicates(ft_atoi(arg[index]), arg, index))
			insert_end(a, ft_atoi(arg[index]));
		else
		{
			if (argc == 2)
				free_str(arg);
			return (0);
		}
		index++;
	}
	if (argc == 2)
		free_str(arg);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		index;

	a = NULL;
	b = NULL;
	index = 0;
	if (argc < 2)
		return (0);
	if (!init_stack(argc, argv, &a, index))
	{
		ft_putstr_fd("Error\n", 2);
		free_list(&a);
		free_list(&b);
		return (0);
	}
	if (!check_sort(a))
	{
		sort(&a, &b);
	}
	free_list(&a);
	free_list(&b);
	return (0);
}
