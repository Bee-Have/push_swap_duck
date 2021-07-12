/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_id_monitoring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:16:41 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/12 15:27:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	get_id(t_list *list, int value)
{
	t_list	*iterator;

	iterator = list;
	while (iterator->next)
	{
		if (iterator->value == value)
			return (iterator->id);
		iterator = iterator->next;
	}
	return (-1);
}

void	place_id(t_list **list)
{
	t_list	*iterator;
	int		new_id;

	if (!(*list))
		return ;
	new_id = 0;
	iterator = *list;
	iterator->id = new_id;
	while (iterator)
	{
		iterator->id = new_id;
		iterator = iterator->next;
		new_id++;
	}
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

int		lst_len(t_list **list)
{
	t_list	*iterator;

	if (!(*list))
		return (0);
	iterator = *list;
	while (iterator->next)
		iterator = iterator->next;
	return (iterator->id + 1);
}
