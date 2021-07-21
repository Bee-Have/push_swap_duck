/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:18:17 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/21 21:27:57 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	visualizer_init_manager(t_list **stack)
{
	t_data	data;
	t_win_info	win_info;
	int		real_width;
	int		real_height;

	real_width = 2560;
	real_height = 1440;
	win_info = mlx_window_info_init();
	win_info.biggest = get_biggest_value(stack);
	win_info.smallest = get_smallest_value(stack);
	win_info.pxl_per_value = calc_pxl_per_node(stack, &win_info.width, real_width);
	mlx_data_init(&data, &win_info);
	visualizer_mlx_update(&data, stack, NULL, &win_info);
}

int		calc_pxl_per_node(t_list **stack, int *width, int real_width)
{
	int		length;
	int		pxl_per_value;

	length = lst_len(stack);
	pxl_per_value = (*width - 1) / length;
	if (pxl_per_value <= 0 && *width == real_width)
	{
		printf("can't get pxl_per_value because under zero\n");
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

void	mlx_data_init(t_data *data, t_win_info *win_info)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, win_info->width, win_info->height
							, "push_swap Visualizer");
	data->img = mlx_new_image(data->mlx, win_info->width, win_info->height);
	data->addr = mlx_get_data_addr(data->img, &(*data).bits_per_pixel
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
