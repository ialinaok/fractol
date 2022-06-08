/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:49:12 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/08 05:26:14 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	put_window_values(t_data *data)
{
	if (data->fractal_set == 0)
	{
		data->win = mlx_new_window(data->mlx, WIN_X, WIN_Y, \
		"Mandelbrot fractol, bby!");
		data->img.img_ptr = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	}
	else if (data->fractal_set >= 1 && data->fractal_set <= 5)
	{
		data->win = mlx_new_window(data->mlx, WIN_X, WIN_Y, \
		"Julia fractol, bby!");
		data->img.img_ptr = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	}
	else if (data->fractal_set == 6)
	{
		data->win = mlx_new_window(data->mlx, WIN_X, WIN_Y, \
		"Burning ship fractol, bby!");
		data->img.img_ptr = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	}
	else if (data->fractal_set == 7)
	{
		data->win = mlx_new_window(data->mlx, X_SIERP, Y_SIERP, \
		"Sierpinski fractol, bby!");
		data->img.img_ptr = mlx_new_image(data->mlx, X_SIERP, Y_SIERP);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (0);
	analyse_input(argc, argv, &data);
	put_window_values(&data);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, \
	&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	data.width = WIN_X;
	data.length = WIN_Y;
	data.f = 1;
	render(&data, 0, 0);
	mlx_hook(data.win, 17, 0, &close_x, &data);
	mlx_key_hook(data.win, &key_hooks, &data);
	mlx_mouse_hook(data.win, mouse_zoom, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	return (0);
}
