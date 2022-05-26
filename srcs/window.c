/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:19:22 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/26 18:01:24 by apielasz         ###   ########.fr       */
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

int	check_set

int	create_image(t_ptr *ptr, t_data *img, char *set)
{
	int	set;

	set = 56;
	if (set == 0) //mandelbrot
	{
		
	}
	else if (set == 1) //julia
}

int	get_started(char *set)
{
	t_ptr	ptr;
	t_data	img;
	
	ptr.mlx = mlx_init();
	if (ptr.mlx == NULL)
		return (0);
	ptr.win = mlx_new_window(ptr.mlx, WIN_X, WIN_Y, "fractol, bby!");
	img.img = mlx_new_image(ptr.mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (find_set(set) == 0) //mandelbrot
		mandelbrot_iter(&ptr, &img);
	create_image(&ptr, &img, set);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
	mlx_key_hook(ptr.win, close_window, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}