/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:11:18 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/03 15:45:09 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_list
{
	char			value;
	struct s_list	*next;
}				t_list;

t_list	*init_stack(int *list, int len);

t_list	*ft_lstnew(char content);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);

void	get_infos(int *list, int len);

void	swap(t_list **list);

//DEBUG
void	print_list(t_list *stack);

#endif