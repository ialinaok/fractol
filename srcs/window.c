/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:19:22 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/31 18:14:02 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_window(int keycode, t_ptr *ptr)
{
	if (keycode == 53)
		mlx_destroy_window(ptr->mlx, ptr->win);
	exit(0);
}

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_started(int set, int color)
{
	t_ptr	ptr;
	t_data	img;
	
	ptr.mlx = mlx_init();
	if (ptr.mlx == NULL)
		return (0);
	ptr.win = mlx_new_window(ptr.mlx, WIN_X, WIN_Y, "fractol, bby!");
	img.img = mlx_new_image(ptr.mlx, WIN_X, WIN_Y);
	img.color_scheme = color;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (set == 0) //mandelbrot
		mandelbrot(&img);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
	mlx_key_hook(ptr.win, close_window, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}