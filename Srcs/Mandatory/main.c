/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:45:32 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/30 16:26:28 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	main(int ac, char **av)
{
	long long int	*list;
	int				iav;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac = ft_tablen((const char **)av);
	}
	iav = 1;
	list = (long long int *)malloc((ac - 1) * sizeof(long long int));
	if (!list)
		return (0);
	while (iav < ac)
	{
		list[iav - 1] = ft_atoi(av[iav]);
		iav++;
	}
	task_manager(list, ac - 1);
	return (0);
}

void	task_manager(long long int *list, int len)
{
	t_list	*a;
	t_list	*b;

	if (check_list(list, len) == -1)
		return ;
	a = init_stack(list, len);
	b = NULL;
	free(list);
	if (check_order(&a) == 0)
		return ;
	if (len > 5)
		big_manager(&a, &b);
	else
		small_manager(&a, &b);
	free_struct(&a);
	free_struct(&b);
	return ;
}

int	check_list(long long int *list, int len)
{
	int				ilist;
	int				icpy;
	long long int	*copy;

	ilist = 0;
	icpy = 0;
	copy = list;
	while (ilist < len)
	{
		if (list[ilist] > INT_MAX || list[ilist] < INT_MIN)
			return (error_message());
		while (icpy < len)
		{
			if (icpy != ilist && copy[icpy] == list[ilist])
				return (error_message());
			icpy++;
		}
		icpy = 0;
		ilist++;
	}
	return (0);
}
