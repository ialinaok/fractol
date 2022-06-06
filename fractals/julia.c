/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:44:56 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/06 13:32:10 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia_init(t_data *data)
{
	data->screen.x_min = -1.6;
	data->screen.x_max = 1.6;
	data->screen.y_min = -1.477;
	data->screen.y_max = 1.5;
}

int	normal_julia_iter(t_complex *z, t_complex c)
{
	int	i;
	double	temp;
	
	i = 0;
	temp = 0;
	while (abs_of_cmplx(*z) <= 2 && i < MAX_ITER)
	{
		temp = pow(z->r, 2) - pow(z->i, 2);
		z->i = 2 * z->r * z->i + c.i;
		z->r = temp + c.r;
		i++;
	}
	return (i);
}

void	normal_julia(t_data *data, double r, double i)
{
	t_complex	z;
	t_complex	c;
	int			iter;
	int			color;

	c.r = r;
	c.i = i;
	data->img.px_y = 0;
	while (data->img.px_y < WIN_Y)
	{
		data->img.px_x = 0;
		while (data->img.px_x < WIN_X)
		{
			z = pxl_to_cmplx(data, data->img.px_x, data->img.px_y);
			iter = normal_julia_iter(&z, c);
			color = paint_my_wrld(iter, data);
			pixel_put(data, color);
			data->img.px_x++;
		}
		data->img.px_y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
