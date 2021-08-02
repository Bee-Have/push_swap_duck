/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:45:32 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/02 13:34:09 by amarini-         ###   ########.fr       */
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
		av = ft_split(av[1], ' ');
	else if (ac > 2)
		av = ft_erase(av, 0, 1);
	iav = 0;
	list = (long long int *)malloc((ft_tablen((const char **)av))
			* sizeof(long long int));
	if (!list)
		return (0);
	while (iav < ft_tablen((const char **)av))
	{
		list[iav] = ft_atoi(av[iav]);
		iav++;
	}
	task_manager(av, list, ft_tablen((const char **)av));
	free(list);
	ft_freetab(av);
	return (0);
}

int	task_manager(char **av, long long int *list, int len)
{
	t_list	*a;
	t_list	*b;

	if (check_input(av) == 1)
		return (error_message());
	if (check_list(list, len) == -1)
		return (-1);
	a = init_stack(list, len);
	b = NULL;
	if (check_order(&a) == 0)
	{
		free_struct(&a);
		return (0);
	}
	if (len > 5)
		big_manager(&a, &b);
	else
		small_manager(&a, &b);
	free_struct(&a);
	free_struct(&b);
	return (0);
}

int	check_input(char **str)
{
	int		row;
	int		i;

	row = 0;
	i = 0;
	while (str[row] != NULL)
	{
		while (str[row][i] != '\0')
		{
			if (ft_isdigit(str[row][i]) == 0)
			{
				i++;
				if (ft_isdigit(str[row][i]) == 0)
					return (1);
				i--;
			}
			i++;
		}
		i = 0;
		row++;
	}
	return (0);
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
