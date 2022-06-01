/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:19:22 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/01 19:20:09 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_hooks(int keycode, t_ptr *ptr)
{
	if (keycode == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win); // is this necessary? aint exit enough?
		exit(0);
	}
	if (keycode >= 123 && keycode <= 126)
		arrow_moves(keycode, ptr);
	return (0);
}

void	arrow_moves(int keycode, t_ptr *ptr)
{
	if (keycode == 123) // KEY_LEFT, xmin&max smaller
		{
			ptr->screen.x_min = ptr->screen.x_min - 1;
			ptr->screen.x_max = ptr->screen.x_max - 1;
		}
	else if (keycode == 124) // KEY_RIGHT
	{
		ptr->screen.x_min = ptr->screen.x_min + 0.1;
		ptr->screen.x_max = ptr->screen.x_max + 0.1;
	}
	else if (keycode == 125) // KEY_DOWN
	{
		ptr->screen.y_min = ptr->screen.y_min - 0.02;
		ptr->screen.y_max = ptr->screen.y_max - 0.02;
	}
	else if (keycode == 126) // KEY_UP
	{
		ptr->screen.y_min = ptr->screen.y_min + 0.02;
		ptr->screen.y_max = ptr->screen.y_max + 0.02;
	}
}

int	close_x(t_ptr *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	ptr->win = NULL;
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
	t_data *data;
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
		mandelbrot(&img, &ptr);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
	mlx_hook(ptr.win, 17, 0, close_x, &ptr);
	mlx_key_hook(ptr.win, key_hooks, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}