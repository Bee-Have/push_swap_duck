/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_visualizer.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:11:35 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/22 18:48:40 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_VISUALIZER_H
# define PUSH_SWAP_VISUALIZER_H


#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <mlx.h>
#include "../Libs/libft_duck/Includes/libft.h"

typedef	struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef	struct s_win_info
{
	int		width;
	int		height;
	int		pxl_per_value;
	int		total_pxl;
	int		biggest;
	int		smallest;
}				t_win_info;

//VISUALIZER
//INITS
void	visualizer_init_manager(t_list **stack);
int		calc_pxl_per_node(t_list **stack, int *width, int real_width);
void	mlx_data_init(t_data *data, t_win_info *win_info);
t_win_info	mlx_window_info_init(void);

void	visualizer_mlx_update(t_data *real_data, t_list **stack_a
							, t_list **stack_b, t_win_info *win_info);
void	stack_pixel_put(t_data *data, t_list **stack, t_win_info *win_info);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
// TEST VISUALIZER
void	mlx_put_square(t_data *img);
int		mlx_redraw(t_data *img);

// STACK ACTIONS SINGLE
void	swap(t_list **stack);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
// DOUBLE
void	double_swap(t_list **stack_a, t_list **stack_b);
void	double_rotate(t_list **stack_a, t_list **stack_b);
void	double_reverse_rotate(t_list **stack_a, t_list **stack_b);

//MAIN
void	task_manager(long long int *list, int len);
int		check_list(long long int *list, int len);

//STACK
t_list	*init_stack(long long int *list, int len);
void	place_id(t_list **list);
int		lst_len(t_list **list);
int		get_id(t_list *list, int value);
int		get_node_sorted_value(t_list **list, int id);
int		get_node_value(t_list **list, int id);
int		get_biggest_value(t_list **list);
int		get_smallest_value(t_list **list);

//ERRORS
int		error_message();

#endif