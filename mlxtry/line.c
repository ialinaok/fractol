/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:00:55 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/07 20:47:07 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

#define WIN_X 500
#define WIN_Y 500

typedef	struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef	struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_vars;

void	pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	draw_horizontal(t_vars *data, int x, int y, int length)
{
	int	color;
	
	color = 0xb01256;
	while (x < x + length)
	{
		pixel_put(data, x, y, color);
		x++;
	}
}

void	draw_vertical(t_vars *data, int x, int y, int length)
{
	int	color;

	color = 0x0789b8;
	while (y < y + length)
	{
		pixel_put(data, x, y, color);
		y++;
	}
}

void	draw_diagonal(t_vars *data, int x, int y, int length)
{
	int	color;

	color = 0x10b807;
	while (y < y + length)
	{
		pixel_put(data, x, y, color);
		x++;
		y++;
	}
}

int	main(void)
{
	t_vars	data;
	int		x = 10;
	int		y = 10;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_X, WIN_Y, "main");
	data.img.img = mlx_new_image(data.mlx, WIN_X, WIN_Y);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	draw_horizontal(&data, 0, 0, 5);
	// draw_vertical(&data, x, y, 50);
	// draw_diagonal(&data, x, y, 50);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_key_hook(data.win, close, &data);
	mlx_loop(data.mlx);
}
