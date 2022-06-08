/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:19:22 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/08 05:29:59 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_hooks(int keycode, t_data *data)
{
	if (keycode == 53)
		close_x(data);
	if (keycode >= 123 && keycode <= 126)
		arrow_moves(keycode, data);
	if (keycode == 49 && data->color_set == 2)
	{
		data->f += 23;
		printf("%f\n", data->f);
		render(data, 0, 0);
	}
	return (0);
}

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
