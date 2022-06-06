/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:42:59 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/06 23:05:07 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	render(t_data *data, int x, int y)
{
	data->width = WIN_X;
	data->length = WIN_Y;
	printf("%d  = fractal set\n", data->fractal_set);
	if (data->fractal_set == 0) // Mandelbrot
		mandelbrot(data, x, y);
	else if (data->fractal_set == 1) // Julia_broccoli
		normal_julia(data, 0, 0);
	else if (data->fractal_set == 2) // Julia_chineese
		normal_julia(data, -0.835, -0.2321);
	else if (data->fractal_set == 3) // Julia_snowflake
		normal_julia(data, -0.70176, -0.3842);
	else if (data->fractal_set == 4) // Julia_medusa
		normal_julia(data, 0.285, 0.01);
	return (0);
}
