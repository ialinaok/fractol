/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:49:12 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/04 16:58:22 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (0);
	analyse_input(argc, argv, &data);
	data.win = mlx_new_window(data.mlx, WIN_X, WIN_Y, "fractol, bby!");
	data.img.img_ptr = mlx_new_image(data.mlx, WIN_X, WIN_Y);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, \
	&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	render(&data);
	mlx_hook(data.win, 17, 0, &close_x, &data);
	mlx_key_hook(data.win, &key_hooks, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	return (0);
}