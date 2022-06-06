/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:19:40 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/06 23:21:00 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot_init(t_data *data)
{
	data->screen.x_min = -2;
	data->screen.x_max = 0.6;
	data->screen.y_min = -1.2;
	data->screen.y_max = 1.2;
}

int	mandelbrot_iter(t_complex *c)
{
	int			i;
	t_complex	z;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	// printf("c.r: %f, c.i: %f in pxl to cmplx\n", c->r, c->i);
	while (abs_of_cmplx(z) <= 2 && i < MAX_ITER)
	{
		z = add_cmplx(multi_cmplx(z, z), c);
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *data, int x, int y)
{
	t_complex	c;
	int			i;
	int			color;

	printf("x: %d, y: %d\n", x, y);
	data->img.px_y = y;
	while (data->img.px_y < data->length)
	{
		data->img.px_x = x;
		while (data->img.px_x < data->width)
		{
			c = pxl_to_cmplx(data, data->img.px_x, data->img.px_y);
			i = mandelbrot_iter(&c);
			// if (x > 0)
			// 	color = 0xFFFFFF;
			color = paint_my_wrld(i, data);
			pixel_put(data, color);
			data->img.px_x++;
		}
		data->img.px_y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
