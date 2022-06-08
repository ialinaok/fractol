/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:52:29 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/07 18:48:17 by apielasz         ###   ########.fr       */
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
	t_coordi	dist;
	double		factor;

	if ((x >= 0 && x <= 936) && (y >= 0 && y <= 864))
	{
		point = pxl_to_cmplx(data, x, y);
		calc_distance(point, &dist, data);
		factor = 0.1;
		if (button == 2 || button == 5) // zoom out // right click // scroll up
		{
			data->screen.x_min = data->screen.x_min - dist.x_min * factor;
			data->screen.x_max = data->screen.x_max + dist.x_max * factor;
			data->screen.y_min = data->screen.y_min - dist.y_min * factor;
			data->screen.y_max = data->screen.y_max + dist.y_max * factor;
		}
		if (button == 1 || button == 4) // zoom in // left click // scroll down
		{
			data->screen.x_min = data->screen.x_min + dist.x_min * factor;
			data->screen.x_max = data->screen.x_max - dist.x_max * factor;
			data->screen.y_min = data->screen.y_min + dist.y_min * factor;
			data->screen.y_max = data->screen.y_max - dist.y_max * factor;
		}
		render(data, 0, 0);
	}
	return (0);
}
