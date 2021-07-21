/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:46:33 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/21 12:25:34 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

//dimentions : 1920/1080 -> 960/540

int	main(void)
{
	t_data	data;


	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 960, 540, "Well hello there General Kenobi!");
	data.img = mlx_new_image(data.mlx, 960, 540);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel
								, &data.line_length, &data.endian);
	mlx_put_square(&data);
	// mlx_loop_hook(data.mlx, mlx_redraw, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}

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

void	mlx_put_square(t_data *img)
{
	int		x;
	int		y;
	int		max;

	x = 100;
	y = 100;
	max = 500;
	while (y < max)
	{
		while (x < max)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
			x++;
		}
		x = 100;
		y++;
	}
}
