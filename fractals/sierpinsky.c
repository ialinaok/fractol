/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:49:18 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/08 13:22:35 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	triangle_recursive(t_data *data, int x, int y, float len, int lvl, int max_iter, int tri)
{
	if (lvl == max_iter)
		draw_small_triangle(data, x, y, len, tri);
	else
	{
		triangle_recursive(data, x, y, len / 2, lvl + 1, max_iter, 1);
		triangle_recursive(data, x, y, len / 2, lvl + 1, max_iter, 2);
		triangle_recursive(data, x, y, len / 2, lvl + 1, max_iter, 3);
	}
}

void	draw_small_triangle(t_data *data, int x, int y, int len, int tri)
{
	if (tri == 1)
	{
		draw_vertical(data, x + len / 2, y, len / 2);
		draw_horizontal(data, x, y + len / 2, len / 2);
		draw_diagonal(data, x + len / 2, y, len / 2);
	}
	else if (tri == 2)
	{
		draw_vertical(data, x + len / 2, y + len, len / 2); // vertical lower
		draw_horizontal(data, x, y + (2 * len) - (len / 2), len / 2); // horizontal lower
		draw_diagonal(data, x + len / 2, y + len, len / 2); // diagonal lower
	}
	else if (tri == 3)
	{
		draw_vertical(data, x + (2 * len) - (len / 2), y, len / 2); // vertical upper
		draw_horizontal(data, x + len, y + len / 2, len / 2); // horizontal upper
		draw_diagonal(data, x + (2 * len) - (len / 2), y, len / 2); // diagonal upper
	}
}
// void	draw_lower(t_data *data, int x_y, int len, int f)
// {
// 	draw_horizontal(data, x_y + len / 2, x_y + (len * 1 / 4), len / 4); // horizontal upper
// 	draw_vertical(data, x_y + (len * 3 / 4), x_y, len / 4); // vertical upper
// 	draw_diagonal(data, x_y + (len * 3 / 4), x_y, len / 4); // diagonal upper
// }

// int	draw_small_triangle_2(t_data *data, int x, int y, int len)
// {
// 	draw_horizontal(data, x, y + (len / 4), len / 4);
// 	draw_vertical(data, x + (len / 4), y, len / 4);
// 	draw_diagonal(data, x + (len / 4), y, len / 4);
	
// 	draw_horizontal(data, x, y + (len * 3 / 4), len / 4); // horizontal lower
// 	draw_vertical(data, x + (len * 1 / 4), y + len / 2, len / 4); // vertical lower
// 	draw_diagonal(data, x + len * 1 / 4, y + len / 2, len / 4); // diagonal lower
	
// 	draw_horizontal(data, x + len / 2, y + (len * 1 / 4), len / 4); // horizontal upper
// 	draw_vertical(data, x + (len * 3 / 4), y, len / 4); // vertical upper
// 	draw_diagonal(data, x + (len * 3 / 4), y, len / 4); // diagonal upper
// }

void	sierpinsky(t_data *data)
{
	int	x_y;
	int	x_diagonal;
	int	len;
	int	lvl = 0;
	int	max_iter = 1;
	
	x_y = 40;
	len = X_SIERP - (2 * x_y);
	x_diagonal = x_y + len;
	draw_big_triangle(data, x_y, x_diagonal, len);
	triangle_recursive(data, x_y, x_y, len, lvl, max_iter, 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}