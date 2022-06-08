/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:49:18 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/08 03:04:02 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// void	draw_small_triangle(t_data *data, int x_y, int len, int f)
// {
// 	int	count;

// 	count = 0;
// 	draw_horizontal(data, x_y, x_y + (len * f), len * f);
// 	draw_vertical(data, x_y + len * f, x_y, len * f;
// 	draw_diagonal(data, x_y + len * f, x_y, len * f;
// 	draw_upper(data, x_y, len, f / 2);
// 	draw_lower(data, x_y, len, f / 2);
// }

// void	draw_upper(t_data *data, int x_y, int len, int f)
// {
// 	draw_horizontal(data, x_y + len * 2 * f, x_y + len * f, len * f); // horizontal upper
// 	draw_vertical(data, x_y + len * 3 * f, x_y, len / 4); // vertical upper
// 	draw_diagonal(data, x_y + (len * 3 / 4), x_y, len / 4); // diagonal upper
// }

// void	draw_lower(t_data *data, int x_y, int len, int f)
// {
// 	draw_horizontal(data, x_y + len / 2, x_y + (len * 1 / 4), len / 4); // horizontal upper
// 	draw_vertical(data, x_y + (len * 3 / 4), x_y, len / 4); // vertical upper
// 	draw_diagonal(data, x_y + (len * 3 / 4), x_y, len / 4); // diagonal upper
// }

// int	draw_small_triangle_2(t_data *data, int x_y, int len)
// {
// 	draw_horizontal(data, x_y, x_y + (len / 4), len / 4);
// 	draw_vertical(data, x_y + (len / 4), x_y, len / 4);
// 	draw_diagonal(data, x_y + (len / 4), x_y, len / 4);
	
// 	draw_horizontal(data, x_y, x_y + (len * 3 / 4), len / 4); // horizontal lower
// 	draw_vertical(data, x_y + (len * 1 / 4), x_y + len / 2, len / 4); // vertical lower
// 	draw_diagonal(data, x_y + len * 1 / 4, x_y + len / 2, len / 4); // diagonal lower
	
// 	draw_horizontal(data, x_y + len / 2, x_y + (len * 1 / 4), len / 4); // horizontal upper
// 	draw_vertical(data, x_y + (len * 3 / 4), x_y, len / 4); // vertical upper
// 	draw_diagonal(data, x_y + (len * 3 / 4), x_y, len / 4); // diagonal upper
// }

void	sierpinsky(t_data *data)
{
	int	x_y;
	int	x_diagonal;
	int	len;
	
	x_y = 40;
	len = X_SIERP - (2 * x_y);
	x_diagonal = x_y + len;
	// draw_big_triangle(data, x_y, x_diagonal, len, 1 / 2);
	// draw_small_triangle(data, x_y, len);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}