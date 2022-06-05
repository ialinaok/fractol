/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:52:29 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/06 01:35:00 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_zoom(int button, int x, int y, t_data	*data)
{
	printf("%d x: %d, y: %d\n", button, x, y);

	if (button == 1) // scroll down == zoom in == decrease the limits
	{
		// printf(" xmax %f --- before\n", data->screen.x_max);
		// printf(" xmin %f --- before\n", data->screen.x_min);
		// printf(" ymax %f --- before\n", data->screen.y_max);
		// printf(" ymin %f --- before\n", data->screen.y_min);
		data->screen.x_max = data->screen.x_max * 1.2;
		data->screen.x_min = data->screen.x_min * 1.2;
		data->screen.y_max = data->screen.y_max * 1.2;
		data->screen.y_min = data->screen.y_min * 1.2;
		// data->screen.x_max = x / WIN_X * (data->screen.x_max - data->screen.x_min) / 1.1;
		// data->screen.x_min = x / WIN_X * (data->screen.x_max - data->screen.x_min) / 1.1;
		// data->screen.x_max = x / WIN_X * (data->screen.x_max - data->screen.x_min) / 1.1;
		// data->screen.x_max = x / WIN_X * (data->screen.x_max - data->screen.x_min) / 1.1;

		// printf(" xmax %f --- scroll down\n", data->screen.x_max);
		// printf(" xmin %f --- scroll down\n", data->screen.x_min);
		// printf(" ymax %f --- scroll down\n", data->screen.y_max);
		// printf(" ymin %f --- scroll down\n", data->screen.y_min);
		// printf(" xmax %f --- scroll down\n", xmax);
		// printf(" xmin %f --- scroll down\n", xmin);
		// printf(" ymax %f --- scroll down\n", ymax);
		// printf(" ymin %f --- scroll down\n", ymin);
	}
	if (button == 2) // scroll up == zoom out == increase the limits
	{
		data->screen.x_max = data->screen.x_max * 0.8;
		data->screen.x_min = data->screen.x_min * 0.8;
		data->screen.y_max = data->screen.y_max * 0.8;
		data->screen.y_min = data->screen.y_min * 0.8;
		printf(" xmax %f === scroll up\n", data->screen.x_max);
	}
	render(data);
	return (0);
}