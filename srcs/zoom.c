/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:52:29 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/06 14:06:23 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	calc_distance(t_complex point, t_coordi *dist, t_data *data)
{
	dist->x_min = point.r - data->screen.x_min;
	dist->x_max = data->screen.x_max - point.r;
	dist->y_min = point.i - data->screen.y_min;
	dist->y_max = data->screen.y_max - point.i;
}

int	mouse_zoom(int button, int x, int y, t_data	*data)
{
	t_complex	point;
	t_coordi		dist;

	point = pxl_to_cmplx(data, x, y);
	calc_distance(point, &dist, data);
	if (button == 2 || button == 5) // zoom out // right click // scroll up
	{
		data->screen.x_min = data->screen.x_min - dist.x_min * 0.1;
		data->screen.x_max = data->screen.x_max + dist.x_max * 0.1;
		data->screen.y_min = data->screen.y_min - dist.y_min * 0.1;
		data->screen.y_max = data->screen.y_max + dist.y_max * 0.1;
	}
	if (button == 1 || button == 4) // zoom in // left click // scroll down
	{
		data->screen.x_min = data->screen.x_min + dist.x_min * 0.1;
		data->screen.x_max = data->screen.x_max - dist.x_max * 0.1;
		data->screen.y_min = data->screen.y_min + dist.y_min * 0.1;
		data->screen.y_max = data->screen.y_max - dist.y_max * 0.1;
	}
	render(data);
	return (0);
}
