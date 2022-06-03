/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:19:22 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/02 23:09:46 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_hooks(int keycode, t_data *data)
{
	if (keycode == 53)
		close_x(data);
	if (keycode >= 123 && keycode <= 126)
		arrow_moves(keycode, data);
	return (0);
}

void	arrow_moves(int keycode, t_data *data)
{
	if (keycode == 123) // KEY_LEFT, xmin&max smaller
	{
		data->screen.x_min = data->screen.x_min - 100;
		data->screen.x_max = data->screen.x_max - 100;
	}
	else if (keycode == 124) // KEY_RIGHT
	{
		data->screen.x_min = data->screen.x_min + 0.1;
		data->screen.x_max = data->screen.x_max + 0.1;
	}
	else if (keycode == 125) // KEY_DOWN
	{
		data->screen.y_min = data->screen.y_min - 0.02;
		data->screen.y_max = data->screen.y_max - 0.02;
	}
	else if (keycode == 126) // KEY_UP
	{
		data->screen.y_min = data->screen.y_min + 0.02;
		data->screen.y_max = data->screen.y_max + 0.02;
	}
}

int	close_x(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	exit(0);
}

void	pixel_put(t_data *data, int color)
{
	char	*dst;

	dst = data->img.addr + (data->img.px_y * data->img.line_length + \
	data->img.px_x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	// write(2, "Pixel putting\n", 15);
}
