#include "push_swap.h"

// void	test_list(int *list, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= len)
// 	{
// 		printf("[%d]", list[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

int		main(int ac, char **av)
{
	int	*list;
	int	iav;
	int	ilist;

	if (ac < 2)
		return (0);
	iav = 1;
	ilist = 0;
	list = (int *)malloc((ac - 1) * sizeof(int));
	if (!list)
		return (0);
	while (iav < ac)
	{
		list[ilist] = ft_atoi(av[iav]);
		iav++;
		ilist++;
	}
	// // test_list(list, ac - 2);
	// if (check_list(list, ac -2) == -1)
	// 	free(list);
	// else
		get_infos(list, ac - 1);
	return (0);
}

void	get_infos(int *list, int len)
{
	t_list	*a;
	t_list	*b;

	a = init_stack(list, len);
	b = NULL;

	print_both_lists(a, b);
	push(&a, &b);
	print_both_lists(a, b);
}

int	check_list(int *list, int len)
{
	int	ilist;
	int	icpy;
	int	*copy;

	ilist = 0;
	icpy = 0;
	copy = list;
	while (ilist < len)
	{
		if (list[ilist] < INT_MAX || list[ilist] < INT_MIN)
			return (-1);
		while (icpy < len)
		{
			if (icpy != ilist && copy[icpy] == list[ilist])
				return (-1);
			icpy++;
		}
		icpy = 0;
		ilist++;
	}
	return (0);
}
