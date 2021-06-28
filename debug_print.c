/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:14:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/28 11:34:49 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *stack)
{
	char	*tmp;
	
	write(1, "[", 1);
	while (stack->next)
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
	char	*tmp;
	
	while (stack_a)
	{
		tmp = ft_strdup(ft_itoa(stack_a->content));
		tmp = ft_strjoin("[", tmp);
		tmp = ft_strjoin(tmp, "]");
		write(1, tmp, ft_strlen(tmp));
		stack_a = stack_a->next;
		free(tmp);
	}
	write(1, " ", 1);
	while (stack_b)
	{
		tmp = ft_strdup(ft_itoa(stack_b->content));
		write(1, tmp, ft_strlen(tmp));
		stack_b = stack_b->next;
		free(tmp);
	}
	write(1, "\n", 1);
	return ;
}
