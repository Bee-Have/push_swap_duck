/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:14:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/28 16:10:06 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//CONTENT OF NODES

void	print_list(t_list *stack)
{
	char	*tmp;

	while (stack)
	{
		tmp = ft_strdup(ft_itoa(stack->content));
		tmp = ft_strjoin("[", tmp);
		tmp = ft_strjoin(tmp, "]");
		write(1, tmp, ft_strlen(tmp));
		stack = stack->next;
		free(tmp);
	}
	write(1, "\n", 1);
	return ;
}

void	print_both_lists(t_list *stack_a, t_list *stack_b)
{
	print_list(stack_a);
	print_list(stack_b);
	return ;
}

// ID OF NODES

void	print_id(t_list *stack)
{
	char	*tmp;

	while (stack)
	{
		tmp = ft_strdup(ft_itoa(stack->id));
		tmp = ft_strjoin("{", tmp);
		tmp = ft_strjoin(tmp, "}");
		write(1, tmp, ft_strlen(tmp));
		stack = stack->next;
		free(tmp);
	}
	write(1, "\n", 1);
	return ;
}

void	print_both_id(t_list *stack_a, t_list *stack_b)
{
	print_id(stack_a);
	print_id(stack_b);
	return ;
}
