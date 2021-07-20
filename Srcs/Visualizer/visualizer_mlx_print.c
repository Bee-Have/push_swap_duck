/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_mlx_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:15:26 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/20 16:01:43 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

//mlx window updater will take mlx data + stack "A" "B" as parameters
void	visualizer_mlx_update(t_data *real_data, t_list **stack_a
							, t_list **stack_b, t_win_info *win_info)
{
	static	t_win_info	window;
	static	t_data	data;

	if (real_data)
		data = *real_data;
	if (win_info)
		window = *win_info;
	stack_pixel_put(&data, stack_a, win_info);
	stack_pixel_put(&data, stack_b, win_info);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
}

void	stack_pixel_put(t_data *data, t_list **stack, t_win_info *win_info)
{
	t_list	*iterator;
	int		i_pxl;
	int		x;
	int		y;

	i_pxl = 0;
	iterator = *stack;
	while (iterator)
	{
		y = iterator->value / (*win_info).height;
		while (y >= 0)
		{
			x = (iterator->id * (*win_info).pxl_per_value) + (*win_info).total_pxl;
			if (iterator->sorted == 0)
				my_mlx_pixel_put((*data).img, x, y, 0x00FF5733);
			else
				my_mlx_pixel_put((*data).img, x, y, 0x0033FF34);
			(*win_info).total_pxl += (x - (*win_info).total_pxl);
			y--;
		}
		iterator = iterator->next;
	}
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
