/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:11:18 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/17 16:01:31 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

t_list	*init_stack(int *list, int len);

// t_list	*ft_lstnew(char content);
// void	ft_lstadd_front(t_list **alst, t_list *new);
// void	ft_lstadd_back(t_list **alst, t_list *new);

void	get_infos(int *list, int len);
int		check_list(int *list, int len);

void	swap(t_list **stack);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

void	double_swap(t_list **stack_a, t_list **stack_b);
void	double_rotate(t_list **stack_a, t_list **stack_b);
void	double_reverse_rotate(t_list **stack_a, t_list **stack_b);

//DEBUG
void	print_list(t_list *stack);
void	print_both_lists(t_list *stack_a, t_list *stack_b);

#endif