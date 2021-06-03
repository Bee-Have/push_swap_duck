/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_managment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:16:41 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/03 15:47:17 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(char content)
{
	int		value;
	t_list	*head;

	value = content;
	head = NULL;
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->value = value;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	new->next = *alst;
	//*alst = new;
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current;

	if (!*alst)
	{
		*alst = new;
		(*alst)->next = NULL;
		return ;
	}
	current = (*alst);
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->next = NULL;
}

/*int	get_stack_id(t_list *list)
{
	t_list	*iterator;
	int		result;

	iterator = list;
	result = 0;
	while (iterator->next != NULL)
	{
		
	}
}*/
