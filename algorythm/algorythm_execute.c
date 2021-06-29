/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:28:33 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/29 12:33:47 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_actions(t_list **stack_a, t_list **stack_b, char **actions)
{
	int		i;

	i = 0;
	while (actions[i] != NULL)
	{
		if (ft_memcmp(actions[i], "rr", ft_strlen(actions[i])) == 0)
			
	}
}