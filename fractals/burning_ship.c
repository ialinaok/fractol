/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:34:43 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/08 04:11:56 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	burning_ship_init(t_data	*data)
{
	data->screen.x_min = -2.1;
	data->screen.x_max = 1.3;
	data->screen.y_min = -1.8;
	data->screen.y_max = 1.3;
}

int	burning_ship_iter(t_complex *c)
{
	int			i;
	t_complex	z;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	while (abs_of_cmplx(z) <= 2 && i < MAX_ITER)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		z = add_cmplx(multi_cmplx(z, z), c);
		i++;
	}
	return (i);
}

void	burning_ship(t_data *data, int x, int y)
{
	t_complex	c;
	int			i;
	int			color;

	data->img.px_y = y;
	while (data->img.px_y < data->length)
	{
		data->img.px_x = x;
		while (data->img.px_x < data->width)
		{
			c = pxl_to_cmplx(data, data->img.px_x, data->img.px_y);
			i = burning_ship_iter(&c);
			color = paint_my_wrld(i, data);
			pixel_put(data, color);
			data->img.px_x++;
		}
		data->img.px_y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
