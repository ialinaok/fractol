/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:19:22 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/06 21:08:50 by apielasz         ###   ########.fr       */
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
