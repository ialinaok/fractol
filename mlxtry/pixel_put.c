/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:44:43 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/26 15:46:28 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*  t_data	img;
	use the function mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, 
	&img.endian); to get the data to our img
	then use pixel_put(&img, x, y, color);
	pixel_put takes an image, doesn't write directly to the window
	finally, you have to push the image to the window:
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
*/