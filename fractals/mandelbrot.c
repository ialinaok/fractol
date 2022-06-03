/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:19:40 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/04 00:39:22 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot_init(t_coordi *screen)
{
	screen->x_min = -2;
	screen->x_max = 0.6;
	screen->y_min = -1.2;
	screen->y_max = 1.2;
}

t_complex	mandelbrot_pxl_to_cmplx(t_data *data)
{
	t_complex	c;

	c.r = data->screen.x_min + (data->img.px_x / (double)WIN_X) \
	* (data->screen.x_max - data->screen.x_min);
	c.i = data->screen.y_min + (data->img.px_y / (double)WIN_Y) \
	* (data->screen.y_max - data->screen.y_min);
	// c.r = ((double)img->px_x - (double)screen->x_zero) * 3 / WIN_X;
	// c.i = ((double)screen->y_zero - (double)img->px_y) * 2 / WIN_Y;
	return (c);
}

int	mandelbrot_iter(t_complex *c)
{
	int			i;
	t_complex	z;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	while (abs_of_cmplx(z) <= 2 && i < MAX_ITER)
	{
		z = add_cmplx(multi_cmplx(z, z), c);
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *data)
{
	t_complex	c;
	int			i;
	int			color;

	data->img.px_y = 0;
	while (data->img.px_y < WIN_Y)
	{
		data->img.px_x = 0;
		while (data->img.px_x < WIN_X)
		{
			c = mandelbrot_pxl_to_cmplx(data);
			i = mandelbrot_iter(&c);
			if (i < MAX_ITER)
			{
				color = paint_my_wrld(i, data);
				pixel_put(data, color);
			}
			data->img.px_x++;
		}
		data->img.px_y++;
	}
}
