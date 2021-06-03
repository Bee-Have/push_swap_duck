/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:14:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/03 15:21:18 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	return ;
}
