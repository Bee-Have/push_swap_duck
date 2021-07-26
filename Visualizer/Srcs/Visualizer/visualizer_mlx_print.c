/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_mlx_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:15:26 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/26 15:54:44 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap_visualizer.h"

void	visualizer_mlx_update(t_data *real_data, t_list **stack_a
							, t_list **stack_b, t_win_info *win_info)
{
	static	t_win_info	window;
	static	t_data	data;
	char	line[10];

	if (real_data)
		data = *real_data;
	if (win_info)
		window = *win_info;
	//check if return of gnl from stdin is not NULL
	//call function to interpret stdin;
	if (check_order(stack_b) == 0)
	{
		write(1, "OK", 2);
		exit(1);
	}
	if (fgets(line, 10, stdin) > 0)
	{
		reader_manager(line, stack_a, stack_b);
		printf("changed\n");
	}
	stack_pixel_put(&data, stack_a, &window);
	stack_pixel_put(&data, stack_b, &window);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	window.total_pxl = 0;
	mlx_loop(data.mlx);
}

void	stack_pixel_put(t_data *data, t_list **stack, t_win_info *win)
{
	t_list	*iterator;
	int		x;
	int		y;

	if (!stack)
		return ;
	iterator = *stack;
	while (iterator)
	{
		y = ((win->height - win->pxl_per_value) * win->min) / iterator->value;
		while (y < win->height)
		{
			x = 0;
			while (x < win->pxl_per_value && y < win->height)
			{
				if (iterator->sorted == 0)
					my_mlx_pixel_put(data, (x + win->total_pxl), y, 0x00FF0000);
				else
					my_mlx_pixel_put(data, (x + win->total_pxl), y, 0x0000FF00);
				x++;
			}
			y++;
		}
		win->total_pxl += win->pxl_per_value;
		iterator = iterator->next;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
