/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:19:22 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/05 17:18:24 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_hooks(int keycode, t_data *data)
{
	if (keycode == 53)
		close_x(data);
	if (keycode >= 123 && keycode <= 126)
		arrow_moves(keycode, data);
	return (0);
}

void	arrow_moves(int keycode, t_data *data)
{
	t_img	temp;

	temp.img_ptr = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	temp.addr = mlx_get_data_addr(temp.img_ptr, &temp.bits_per_pixel, &temp.line_length, &temp.endian);
	if (keycode == 123) // KEY_LEFT
	{
		data->screen.x_min = data->screen.x_min + 0.05;
		data->screen.x_max = data->screen.x_max + 0.05;
	}
	else if (keycode == 124) // KEY_RIGHT, xmin&max smaller
	{
		data->screen.x_min = data->screen.x_min - 0.05;
		data->screen.x_max = data->screen.x_max - 0.05;
	}
	else if (keycode == 125) // KEY_DOWN
	{
		data->screen.y_min = data->screen.y_min - 0.05;
		data->screen.y_max = data->screen.y_max - 0.05;
	}
	else if (keycode == 126) // KEY_UP
	{
		data->screen.y_min = data->screen.y_min + 0.05;
		data->screen.y_max = data->screen.y_max + 0.05;
	}
	// put_image_to_image(&temp, &data->img, 18, 0);
	// data->img = temp;
	render(data);
}

// void	put_image_to_image(t_img *dest, t_img *src, int x_offset, int y_offset)
// {
// 	int		y;
// 	char	*dest_offset;
// 	char	*src_offset;

// 	y = y_offset;
// 	while (y <= dest->px_y)
// 	{
// 		dest_offset = dest->addr + y * \
// 			dest->line_length + x_offset * (dest->bits_per_pixel / 8);
// 		src_offset = src->addr + \
// 			(y - y_offset) * src->line_length;
// 		// ft_memmove(dest_offset, src_offset, ((((t_img *)src)->px_x - x_offset) * 4));
// 		ft_memmove(dest_offset, src_offset, 4);
// 		y++;
// 	}
// }

// void	copy_image(t_data *data, int keycode)
// {
// 	t_img	temp;

// 	if (keycode == 123) // KEY_LEFT
// 	{
// 		data->img.px_y = 0;
// 		temp.px_y = 0;
// 		while (temp.px_y < WIN_Y)
// 		{
// 			data->img.px_x = 0;
// 			temp.px_x = 18;
// 			while (temp.px_x < WIN_X)
// 			{
				
// 			}
// 		}
// 	}
// }

int	close_x(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	exit(0);
}

void	pixel_put(t_data *data, int color)
{
	char	*dst;

	dst = data->img.addr + (data->img.px_y * data->img.line_length + \
	data->img.px_x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
