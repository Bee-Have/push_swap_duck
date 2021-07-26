/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_read_entry.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:41:51 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/26 15:55:47 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap_visualizer.h"

void	reader_manager(char *line, t_list **stack_a, t_list **stack_b)
{
	//probably a problem here
	line = ft_substr(line, 0, ft_strlen(line) - 1);
	//reader will first check if line is correct
	//if parser sends back -1 -> send error message && quit
	if (reader_parser(line) == -1)
	{
		error_message();
		exit(1);
	}
	//then interpret line
	//which will change line accordinglys
	reader_actions_execute(line, stack_a, stack_b);
	// visualizer_mlx_update(NULL, stack_a, stack_b, NULL);
	return ;
}

int		reader_parser(char *line)
{
	//check if line = any of the operations
	//if not sends back -1
	if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0 
		|| ft_strcmp(line, "ss") == 0 || ft_strcmp(line, "pa") == 0 
		|| ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "ra") == 0 
		|| ft_strcmp(line, "rb") == 0 || ft_strcmp(line, "rr") == 0 
		|| ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0 
		|| ft_strcmp(line, "rrr") == 0)
		return (1);
	else
		return (-1);
	//else return -1
	return (-1);
}

void	reader_actions_execute(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(line, "sa") == 0)
		double_swap(stack_a, stack_b);
	else if (ft_strcmp(line, "pa") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(line, "pb") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(line, "rr") == 0)
		double_rotate(stack_a, stack_b);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(line, "rrr") == 0)
		double_reverse_rotate(stack_a, stack_b);
	return ;
}
