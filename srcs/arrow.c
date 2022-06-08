/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:07:27 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/07 18:52:31 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	arrow_moves(int keycode, t_data *data)
{
	double	x_range;
	double	y_range;

	x_range = data->screen.x_max - data->screen.x_min;
	y_range = data->screen.y_max - data->screen.y_min;
	if (keycode == 123) // KEY_LEFT
	{
		// data->screen.x_min = data->screen.x_min - (0.05 * x_range);
		// data->screen.x_max = data->screen.x_max - (0.05 * x_range);
		left_arrowkey(data, x_range);
	}
	else if (keycode == 124) // KEY_RIGHT, xmin&max smaller
	{
		// data->screen.x_min = data->screen.x_min + (0.05 * x_range);
		// data->screen.x_max = data->screen.x_max + (0.05 * x_range);
		right_arrowkey(data, x_range);
	}
	else if (keycode == 125) // KEY_DOWN
	{
		// data->screen.y_min = data->screen.y_min + (0.05 * y_range);
		// data->screen.y_max = data->screen.y_max + (0.05 * y_range);
		down_arrowkey(data, y_range);
	}
	else if (keycode == 126) // KEY_UP
	{
		// data->screen.y_min = data->screen.y_min - (0.05 * y_range);
		// data->screen.y_max = data->screen.y_max - (0.05 * y_range);
		up_arrowkey(data, y_range);
	}
}

void	right_arrowkey(t_data *data, double x_range)
{
	int	i;

	i = 0;
	while (i < data->width * data->length * 4)
	{
		ft_memmove(data->img.addr + i, data->img.addr + 18 * 4 + i, (data->img.line_length - 18) * 4);
		i += data->img.line_length * 4;
	}
	data->width = WIN_X;
	data->screen.x_min = data->screen.x_min + ((18.0/WIN_X) * x_range);
	data->screen.x_max = data->screen.x_max + ((18.0/WIN_X) * x_range);
	render(data, data->width - 18, 0);
	data->width = WIN_X;
	data->length = WIN_Y;
}

void	left_arrowkey(t_data *data, double x_range)
{
	int	i;

	i = 0;
	while (i < data->width * data->length * 4)
	{
		ft_memmove(data->img.addr + 18 * 4 + i, data->img.addr + i, (data->img.line_length - 18) * 4);
		i += data->img.line_length * 4;
	}
	data->width = 18;
	data->screen.x_min = data->screen.x_min - ((18.0/WIN_X) * x_range);
	data->screen.x_max = data->screen.x_max - ((18.0/WIN_X) * x_range);
	render(data, 0, 0);
	data->width = WIN_X;
	data->length = WIN_Y;
}

void	up_arrowkey(t_data *data, double y_range)
{
	ft_memmove(data->img.addr + (18 * WIN_X * 4), data->img.addr, (WIN_Y - 18) * WIN_X * 4);
	data->length = 18;
	data->screen.y_min = data->screen.y_min - ((18.0/WIN_Y) * y_range);
	data->screen.y_max = data->screen.y_max - ((18.0/WIN_Y) * y_range);
	render(data, 0, 0);
	data->width = WIN_X;
	data->length = WIN_Y;
}

void	down_arrowkey(t_data *data, double y_range)
{
	ft_memmove(data->img.addr, data->img.addr + (18 * WIN_X * 4), (WIN_Y - 18) * WIN_X * 4);
	data->length = WIN_Y;
	data->screen.y_min = data->screen.y_min + ((18.0/WIN_Y) * y_range);
	data->screen.y_max = data->screen.y_max + ((18.0/WIN_Y) * y_range);
	render(data, 0, WIN_Y - 18);
	data->width = WIN_X;
	data->length = WIN_Y;
}