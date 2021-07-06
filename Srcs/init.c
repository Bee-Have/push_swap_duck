#include "../Includes/push_swap.h"

int		main(int ac, char **av)
{
	long long int	*list;
	int	iav;
	int	ilist;

	if (ac < 2)
		return (0);
	iav = 1;
	ilist = 0;
	list = (long long int *)malloc((ac - 1) * sizeof(long long int));
	if (!list)
		return (0);
	while (iav < ac)
	{
		list[ilist] = ft_atoi(av[iav]);
		iav++;
		ilist++;
	}
	if (check_list(list, ac - 1) == -1)
		return (0);
	get_infos(list, ac - 1);
	return (0);
}

void	get_infos(long long int *list, int len)
{
	t_list	*a;
	t_list	*b;

	a = init_stack(list, len);
	b = NULL;
	print_list(a);
	algorythm_manager(&a, &b);
	// print_both_lists(a, b);
	// print_both_id(a, b);
}

int	check_list(long long int *list, int len)
{
	int	ilist;
	int	icpy;
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
