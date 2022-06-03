/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:49:12 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/03 19:24:54 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (0);
	// data.fractal_set = -1;
	// data.color_set = -1;
	if (argc < 2)
		show_error_msg();
	if (argv[1])
		data.fractal_set = find_set(argv[1]);
	if (argv[2])
		data.color_set = find_color(argv[2]);
	data.win = mlx_new_window(data.mlx, WIN_X, WIN_Y, "fractol, bby!");
	data.img.img_ptr = mlx_new_image(data.mlx, WIN_X, WIN_Y);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, \
	&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	render(&data);
	mlx_hook(data.win, 17, 0, close_x, &data);
	// mlx_loop_hook(data.mlx, &render, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
	mlx_key_hook(data.win, &key_hooks, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	return (0);
}