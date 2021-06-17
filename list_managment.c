/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_managment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:16:41 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/17 10:39:09 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//wtf is this ?

/*int	get_stack_id(t_list *list)
{
	t_list	*iterator;
	int		result;

	iterator = list;
	result = 0;
	while (iterator->next != NULL)
	{
		
	}
}*/

t_list	*get_last(t_list **list)
{
	t_list	*iterator;

	iterator = *list;
	while (iterator->next)
		iterator = iterator->next;
	return (iterator);
}
