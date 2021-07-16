/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:18:17 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/16 17:49:00 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	visualizer_init_manager(t_list **stack)
{
	t_data	*data;
	//setup default width + height
	//call function to determine width of pixel per value
	//call function to determine height of value by height value
	//send everything to the init mlx window
	//then it will send all of it to the mlx window updater
}

//mlx init window will do exactly that, init the window and the values needed
t_data	*visualizer_mlx_init(t_list **stack, int width, int height)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 960, 540, "push_swap Visualizer");
	data.img = mlx_new_image(data.mlx, 960, 540);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel
								, &data.line_length, &data.endian);
	return (&data);
}

int		calc_pxl_per_value(t_list **stack, int *width, int screen_width)
{
	t_list	*iterator;
	int		length;
	int		pxl_per_value;

	iterator = *stack;
	length = lst_len(stack);
	screen_width = 0;
	pxl_per_value = (*width) / length;
	if (pxl_per_value <= 0)
	{
		*width = (*width) * 2;
		if ((*width) > )
	}
}

//mlx window updater will take mlx data + stack "A" "B" as parameters
//it will then start to update using loop_hook + loop;
//then the actions will send stacks and NULL data
//the data will be used to update everything and will continue to :
//"turn on itself" util next action