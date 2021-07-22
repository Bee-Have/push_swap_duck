/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:47:51 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/22 18:52:55 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap_visualizer.h"

t_list	*init_stack(long long int *list, int len)
{
	t_list	*stack;
	t_list	*iterator;
	int		i;

	i = 0;
	stack = ft_lstnew(list[0]);
	stack->id = i;
	i++;
	iterator = stack;
	while (i < len)
	{
		iterator->next = ft_lstnew(list[i]);
		iterator = iterator->next;
		i++;
	}
	place_id(&stack);
	return (stack);
}
