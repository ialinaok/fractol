/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:42:59 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/03 17:47:43 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	render(t_data *data)
{
	// ft_bzero(data->img.addr, WIN_X * WIN_Y * 4);
	if (data->fractal_set == 0) // Mandelbrot
	{
		// printf("TEST_TEST\n");
		// mandelbrot(data);
		dumb_shit(data);
	}
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

// int	get_started(t_data *data)
// {
// 	data->mlx = mlx_init();
// 	if (data->mlx == NULL)
// 		return (0);
// 	data->win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "fractol, bby!");
// 	data->img.img_ptr = mlx_new_image(data->mlx, WIN_X, WIN_Y);
// 	data->img.addr = mlx_get_data_addr(data->img.img_ptr, \
// 	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
// 	// if (data->fractal_set == 0)
// 	// 	mandelbrot_init(&data->screen);
// 	// mlx_loop_hook(data->mlx, render, &data);
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
// 	mlx_hook(data->win, 17, 0, close_x, &data);
// 	mlx_key_hook(data->win, &key_hooks, &data);
// 	mlx_loop(data->mlx);
// 	return (0);
// }