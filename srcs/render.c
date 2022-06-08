/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:42:59 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/08 03:59:36 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	render(t_data *data, int x, int y)
{
	t_complex	julia;

	define_julias(data, &julia);
	if (data->fractal_set == 0) // Mandelbrot
		mandelbrot(data, x, y);
	else if (data->fractal_set == 1) // Julia_elegant
		normal_julia(data, &julia, x, y);
	else if (data->fractal_set == 2) // Julia_chineese
		normal_julia(data, &julia, x, y);
	else if (data->fractal_set == 3) // Julia_snowflake
		normal_julia(data, &julia, x, y);
	else if (data->fractal_set == 4) // Julia_medusa
		normal_julia(data, &julia, x, y);
	else if (data->fractal_set == 5) // Julia_detail
		normal_julia(data, &julia, x, y);
	else if (data->fractal_set == 6)
		burning_ship(data, x, y);
	else if (data->fractal_set == 7) // sierpinsky
		sierpinsky(data);
	return (0);
}

void	define_julias(t_data *data, t_complex *julia)
{
	if (data->fractal_set == 1)
	{
		julia->r = -0.75;
		julia->i = 0.047;
	}
	else if (data->color_set == 2)
	{
		julia->r = -0.835;
		julia->i = -0.2321;
	}
	else if (data->fractal_set == 3)
	{
		julia->r = -0.70176;
		julia->i = -0.3842;
	}
	else if (data->fractal_set == 4)
	{
		julia->r = 0.285;
		julia->i = 0.01;
	}
	else if (data->fractal_set == 6)
	{
		julia->r = -0.74543;
		julia->i = 0.113;
	}
}
