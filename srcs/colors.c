/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:56:26 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/08 05:29:23 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	move_me(int iterations, t_data *data)
{
	data->trgb.r = sin(0.1 * iterations + 20 + data->f) * 127.5 + 127.5;
	data->trgb.g = sin(0.15 * iterations + 40 + data->f) * 127.5 + 127.5;
	data->trgb.b = sin(0.2 * iterations + 60) * 127.5 + 127.5;
}

void	default_color(int iterations, t_data *data)
{
	float x;

	if (iterations == MAX_ITER)
	{
		data->trgb.r = 0x00;
		data->trgb.g = 0x00;
		data->trgb.b = 0x00;
	}
	else
	{
		x = (double)iterations / MAX_ITER;
		data->trgb.r = 9 * (1 - x) * pow(x, 3) * 255 + 100;
		data->trgb.g = 23 * pow((1 - x), 2) * pow(x, 2) * 255;
		data->trgb.b = 8.5 * pow((1 - x), 3) * x * 255 + 40;
	}
}

void	bernstein(int iterations, t_data *data)
{
	float	x;

	if (iterations == MAX_ITER)
	{
		data->trgb.r = 0x00;
		data->trgb.g = 0x00;
		data->trgb.b = 0x00;
	}
	else
	{
		x = (double)iterations / MAX_ITER;
		data->trgb.r = 40 * (1 - x) * pow(x, 3) * 255;
		data->trgb.g = 3 * pow((1 - x), 2) * pow(x, 2) * 255;
		data->trgb.b = 7 * pow((1 - x), 3) * x * 255;
	}
}

void	blue(int iterations, t_data *data)
{
	float x;

	if (iterations == MAX_ITER)
	{
		data->trgb.r = 0x00;
		data->trgb.g = 0x00;
		data->trgb.b = 0x00;
	}
	else
	{
		x = (double)iterations / MAX_ITER;
		data->trgb.r = 9 * (1 - x) * pow(x, 3) * 255;
		data->trgb.g = 23 * pow((1 - x), 2) * pow(x, 2) * 255;
		data->trgb.b = 8.5 * pow((1 - x), 3) * x * 255;
	}
}

int	paint_my_wrld(int iterations, t_data *data)
{
	if (data->color_set == -1) // default
		default_color(iterations, data);
	else if (data->color_set == 0) // Bernstein
		bernstein(iterations, data);
	else if (data->color_set == 1) // Blue
		blue(iterations, data);
	else if (data->color_set == 2)
		move_me(iterations, data);
	return (create_trgb(data->trgb.t, data->trgb.r, \
	data->trgb.g, data->trgb.b));
}
