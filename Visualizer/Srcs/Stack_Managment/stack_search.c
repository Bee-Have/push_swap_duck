/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:16:41 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/22 19:40:48 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap_visualizer.h"

int	get_id(t_list *list, int value)
{
	t_list	*iterator;

	iterator = list;
	while (iterator)
	{
		if (iterator->value == value)
			return (iterator->id);
		iterator = iterator->next;
	}
	return (0);
}

int		get_node_sorted_value(t_list **list, int id)
{
	t_list	*iterator;

	if (id < 0)
		return ((*list)->sorted);
	iterator = *list;
	while (iterator->next && iterator->id != id)
		iterator = iterator->next;
	return (iterator->sorted);
}

int		get_node_value(t_list **list, int id)
{
	t_list	*iterator;

	iterator = *list;
	if (id < 0)
		return ((*list)->value);
	while (iterator->next && iterator->id != id)
		iterator = iterator->next;
	return (iterator->value);
}

int		get_biggest_value(t_list **list)
{
	t_list	*iterator;
	int		biggest;

	biggest = INT_MIN;
	iterator = *list;
	while (iterator)
	{
		if (iterator->value > biggest)
			biggest = iterator->value;
		iterator = iterator->next;
	}
	return (biggest);
}

int		get_smallest_value(t_list **list)
{
	t_list	*iterator;
	int		smallest;

	smallest = INT_MAX;
	iterator = *list;
	while (iterator)
	{
		if (iterator->value < smallest)
			smallest = iterator->value;
		iterator = iterator->next;
	}
	return (smallest);
}
