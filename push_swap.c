/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:54:58 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/17 14:13:50 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_infos(int *list, int len)
{
	t_list	*a;
	t_list	*b;

	a = init_stack(list, len);
	b = NULL;

	print_list(a);
	// swap(&a);
	// push(&a, &b);
	// rotate(&a);
	reverse_rotate(&a);
	print_list(a);
}