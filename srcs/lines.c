/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:37:48 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/08 00:03:07 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_horizontal(t_data *data, int x, int y, int length)
{
	int	color;

	color = 0xb01256;
	data->img.px_x = x;
	data->img.px_y = y;
	while (data->img.px_x < x + length)
	{
		pixel_put(data, color);
		data->img.px_x++;
	}
}

void	draw_vertical(t_data *data, int x, int y, int length)
{
	int	color;

	color = 0x0789b8;
	data->img.px_x = x;
	data->img.px_y = y;
	while (data->img.px_y < y + length)
	{
		pixel_put(data, color);
		data->img.px_y++;
	}
}

void	draw_diagonal(t_data *data, int x, int y, int length)
{
	int	color;

	color = 0x10b807;
	data->img.px_x = x;
	data->img.px_y = y;
	while (data->img.px_y < y + length)
	{
		pixel_put(data, color);
		data->img.px_x--;
		data->img.px_y++;
	}
}

void	draw_big_triangle(t_data *data, int x_y, int x_diagonal, int len)
{
	draw_diagonal(data, x_diagonal, x_y, len);
	draw_vertical(data, x_y, x_y, len);
	draw_horizontal(data, x_y, x_y, len);
}
