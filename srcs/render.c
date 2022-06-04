/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:42:59 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/04 16:57:56 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	render(t_data *data)
{
	if (data->fractal_set == 0) // Mandelbrot
	{
		mandelbrot(data);
		// dumb_shit(data);
	}
	else if (data->fractal_set == 1) // Julia_broccoli
		normal_julia(data, -0.7269, 0.1889);
	else if (data->fractal_set == 2) // Julia_chineese
		normal_julia(data, -0.835, -0.2321);
	else if (data->fractal_set == 3) // Julia_snowflake
		normal_julia(data, -0.70176, -0.3842);
	else if (data->fractal_set == 4) // Julia_medusa
		normal_julia(data, 0.285, 0.01);
	return (0);
}

int	dumb_colors(void)
{
	t_trgb	trgb;

	trgb.t = 0x00;
	trgb.r = 0xFF;
	trgb.g = 0x55;
	trgb.b = 0x23;
	return (create_trgb(trgb.t, trgb.r, trgb.g, trgb.b));
}

void	dumb_shit(t_data *data)
{
	int			color;

	data->img.px_y = 0;
	while (data->img.px_y < WIN_Y)
	{
		data->img.px_x = 0;
		while (data->img.px_x < WIN_X)
		{
			color = dumb_colors();
			pixel_put(data, color);
		}
		data->img.px_x++;
	}
	data->img.px_y++;
}
