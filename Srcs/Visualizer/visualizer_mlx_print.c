/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_mlx_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:15:26 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/22 10:44:21 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	visualizer_mlx_update(t_data *real_data, t_list **stack_a
							, t_list **stack_b, t_win_info *win_info)
{
	static	t_win_info	*window = NULL;
	static	t_data	*data = NULL;

	if (real_data)
		data = real_data;
	if (win_info)
		window = win_info;
	stack_pixel_put(data, stack_a, win_info);
	stack_pixel_put(data, stack_b, win_info);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}

void	stack_pixel_put(t_data *data, t_list **stack, t_win_info *win_info)
{
	t_list	*iterator;
	int		x;
	int		y;
	int		y_max;

	if (!stack)
		return ;
	iterator = *stack;
	while (iterator)
	{
		if (win_info->smallest == 0)
			y_max = (win_info->pxl_per_value * iterator->value) / (win_info->smallest + 1);
		else
			y_max = (win_info->pxl_per_value * iterator->value) / win_info->smallest;
		y = win_info->height - 1;
		while (y >= y_max)
		{
			printf("y-[%d]\n", y);
			x = 0;
			while (x < win_info->pxl_per_value)
			{
				// printf("x-[%d] y-[%d]\n", x, y);
				if (iterator->sorted == 0)
					my_mlx_pixel_put(data, (x + win_info->total_pxl), y, 0x00FF0000);
				else
					my_mlx_pixel_put(data, (x + win_info->total_pxl), y, 0x0000FF00);
				x++;
			}
			y--;
		}
		win_info->total_pxl += win_info->pxl_per_value;
		iterator = iterator->next;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
