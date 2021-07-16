/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_mlx_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:15:26 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/16 17:26:01 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	visualizer_mlx_update(t_data *data, t_list **stack_a, t_list **stack_b)
{
	
}

//mlx window updater will take mlx data + stack "A" "B" as parameters
//it will then start to update using loop_hook + loop;
//then the actions will send stacks and NULL data
//the data will be used to update everything and will continue to :
//"turn on itself" util next action
