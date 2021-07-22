/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:11:18 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/22 12:37:00 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#if defined __has_include
#	if __has_include (<mlx.h>)
#		include <mlx.h>
#	endif
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../Libs/libft/Includes/libft.h"

t_list	*init_stack(long long int *list, int len);

void	task_manager(long long int *list, int len);
int		check_list(long long int *list, int len);

void	swap(t_list **stack);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

void	double_swap(t_list **stack_a, t_list **stack_b);
void	double_rotate(t_list **stack_a, t_list **stack_b);
void	double_reverse_rotate(t_list **stack_a, t_list **stack_b);

//ALGO MANAGER
void	algorythm_manager(t_list **stack_a, t_list **stack_b);

//ALGO PRE_SORTING

//ALGO MOVE CALCULATOR
char	**moves_calculator_manager(t_list **stack_a, t_list **stack_b);
char	**calc_moves_stack(t_list **stack, int id, char *denominator);
int		get_best_B_id(t_list **stack, int a_value);
char	**check_common_moves(char **moves_a, char **moves_b);

//ALGO FINISH
int		check_order(t_list **stack);
char	**calc_order_moves(t_list **stack);
char	**calc_final_moves(t_list **stack);

//ALGO EXECUTE
void	execute_actions(t_list **stack_a, t_list **stack_b, char **actions);
char	**calc_final_moves(t_list **stack);

//ALGO UTILS
int		find_node_pos(t_list **stack, char **move, char *denominator, int id);

//STACK ID NODES MONITORING
void	place_id(t_list **list);
int		lst_len(t_list **list);

int		get_id(t_list *list, int value);
int		get_node_sorted_value(t_list **list, int id);
int		get_node_value(t_list **list, int id);
int		get_biggest_value(t_list **list);
int		get_smallest_value(t_list **list);

//ERRORS
int		error_message();

//DEBUG
void	print_list(t_list *stack);
void	print_both_lists(t_list *stack_a, t_list *stack_b);
void	print_id(t_list *stack);
void	print_both_id(t_list *stack_a, t_list *stack_b);

#endif
