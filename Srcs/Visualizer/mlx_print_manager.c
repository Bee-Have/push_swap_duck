/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:15:26 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/15 18:33:50 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int		mlx_redraw(t_data *data)
{
	//all this will be replaced by all the calculs that i need to print sorting
	int		width;
	int		height;
	int		max;

	width = 100;
	height = 100;
	max = 500;
	while (height < max)
	{
		while (width < max)
		{
			my_mlx_pixel_put(data, width, height, 0x00FF0000);
			width++;
		}
		width = 100;
		height++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
