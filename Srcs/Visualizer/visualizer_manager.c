/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:18:17 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/19 19:58:07 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	visualizer_init_manager(t_list **stack)
{
	t_data	data;
	t_win_info	win_info;
	int		real_width;
	int		real_height;

	win_info = mlx_window_info_init();
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, win_info.width, win_info.height
							, "push_swap Visualizer");
	mlx_get_screen_size(data.mlx, &real_width, &real_height);
	//setup default width + height
	//call function to determine width of pixel per value
	win_info.pxl_per_value = calc_pxl_per_node(stack, &win_info.width, real_width);
	//send everything to the init mlx window
	visualizer_mlx_init(&data);
	//then it will send all of it to the mlx window updater
	visualizer_mlx_update(&data, stack, NULL, win_info.pxl_per_value);
}

int		calc_pxl_per_node(t_list **stack, int *width, int real_width)
{
	int		length;
	int		pxl_per_value;

	length = lst_len(stack);
	pxl_per_value = (*width) / length;
	if (pxl_per_value <= 0 && *width == real_width)
	{
		error_message();
		exit(1);
	}
	if (pxl_per_value <= 0)
	{
		*width = (*width) * 2;
		if ((*width) > real_width)
			*width = real_width;
		pxl_per_value = calc_pxl_per_node(stack, width, real_width);
	}
	return (pxl_per_value);
}

void	mlx_data_init(t_data *data)
{
	t_data	data;

	// data.mlx = mlx_init();
	// data.win = mlx_new_window(data.mlx, 960, 540, "push_swap Visualizer");
	(*data).img = mlx_new_image((*data).mlx, 960, 540);
	(*data).addr = mlx_get_data_addr((*data).img, &(*data).bits_per_pixel
								, &(*data).line_length, &(*data).endian);
}

t_win_info	mlx_window_info_init(void)
{
	t_win_info	win_info;

	win_info.width = 960;
	win_info.height = 540;
	win_info.pxl_per_value = 0;
	win_info.total_pxl = 0;
	return (win_info);
}
