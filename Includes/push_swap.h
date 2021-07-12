/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:11:18 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/12 18:44:20 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../Libs/libft/Includes/libft.h"

t_list	*init_stack(long long int *list, int len);

void	get_infos(long long int *list, int len);
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

//ALGO EXECUTE
void	execute_actions(t_list **stack_a, t_list **stack_b, char **actions);

//STACK ID NODES MONITORING
int		get_id(t_list *list, int value);
void	place_id(t_list **list);
int		get_node_sorted_value(t_list **list, int id);
int		get_node_value(t_list **list, int id);
int		lst_len(t_list **list);

//ERRORS
int		error_message();

//DEBUG
void	print_list(t_list *stack);
void	print_both_lists(t_list *stack_a, t_list *stack_b);
void	print_id(t_list *stack);
void	print_both_id(t_list *stack_a, t_list *stack_b);

#endif