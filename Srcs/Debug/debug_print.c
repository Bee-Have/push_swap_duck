/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:14:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/29 17:04:33 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

//CONTENT OF NODES

void	print_struct(t_list *stack)
{
	char	*tmp;
	char	*tmp_tmp;

	while (stack)
	{
		tmp_tmp = ft_itoa(stack->value);
		tmp = ft_strdup(tmp_tmp);
		free(tmp_tmp);
		tmp_tmp = ft_strjoin("[", tmp);
		free(tmp);
		tmp = ft_strjoin(tmp_tmp, "]");
		free(tmp_tmp);
		write(1, tmp, ft_strlen(tmp));
		stack = stack->next;
		free(tmp);
	}
	write(1, "\n", 1);
	return ;
}

void	print_both_struct(t_list *stack_a, t_list *stack_b)
{
	print_struct(stack_a);
	print_struct(stack_b);
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
