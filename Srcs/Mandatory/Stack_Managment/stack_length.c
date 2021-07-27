/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:23:18 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/27 17:09:18 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/push_swap.h"

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

int	struct_len(t_list **list)
{
	t_list	*iterator;

	if (!(*list))
		return (0);
	iterator = *list;
	while (iterator->next)
		iterator = iterator->next;
	return (iterator->id + 1);
}
