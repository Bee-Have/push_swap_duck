/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:11:18 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/02 12:26:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../Libs/libft/Includes/libft.h"

t_list	*init_stack(long long int *list, int len);
void	free_struct(t_list **stack);

int		task_manager(char **av, long long int *list, int len);
int		check_list(long long int *list, int len);
int		check_input(char **str);

void	swap(t_list **stack);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

void	double_swap(t_list **stack_a, t_list **stack_b);
void	double_rotate(t_list **stack_a, t_list **stack_b);
void	double_reverse_rotate(t_list **stack_a, t_list **stack_b);

//ALGO MANAGER
void	big_manager(t_list **stack_a, t_list **stack_b);
void	small_manager(t_list **stack_a, t_list **stack_b);

//ALGO SMALL MOVE CALCULATOR
char	**get_smallest_value_out(t_list **stack, char *denominator);
char	**small_sorting_moves(t_list **stack);
char	**small_final_moves(t_list **stack);

//ALGO BIG MOVE CALCULATOR
char	**big_moves_manager(t_list **stack_a, t_list **stack_b);
char	**moves_stack(t_list **stack, int id, char *denominator);
int		best_B_id(t_list **stack, int a_value);
char	**big_common_moves(char **moves_a, char **moves_b);
char	**big_final_moves(t_list **stack);

//ALGO COMMON
int		check_order(t_list **stack);
int		find_node_pos(t_list **stack, char **move, char *denominator, int id);
char	**calc_order_moves(t_list **stack);
char	**fill_moves(char *fill, int length);
char	**tabjoin_free(char **tab1, char **tab2, int freetab);
void	free_both_moves(char **tab1, char **tab2);

//ALGO EXECUTOR
void	execute_actions(t_list **stack_a, t_list **stack_b, char **actions);
void	actions_interpretor(char *action, t_list **stack_a, t_list **stack_b);

//STACK ID NODES MONITORING
void	place_id(t_list **list);
int		struct_len(t_list **list);

int		get_id(t_list *list, int value);
int		get_node_sorted_state(t_list **list, int id);
int		get_node_value(t_list **list, int id);
int		get_biggest_value(t_list **list);
int		get_smallest(t_list **list);

//ERRORS
int		error_message(void);

//DEBUG
void	print_struct(t_list *stack);
void	print_both_struct(t_list *stack_a, t_list *stack_b);
void	print_id(t_list *stack);
void	print_both_id(t_list *stack_a, t_list *stack_b);

#endif
