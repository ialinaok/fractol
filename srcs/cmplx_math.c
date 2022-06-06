/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmplx_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:25:01 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/06 13:35:36 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	abs_of_cmplx(t_complex z)
{
	return (sqrt(pow(z.r, 2) + pow(z.i, 2)));
}

t_complex	add_cmplx(t_complex z, t_complex *c)
{
	t_complex	ret;

	ret.r = z.r + c->r;
	ret.i = z.i + c->i;
	return (ret);
}

t_complex	multi_cmplx(t_complex z, t_complex c)
{
	t_complex	ret;
	
	ret.r = (z.r * c.r) - (z.i * c.i);
	ret.i = (z.r * c.i) + (z.i * c.r);
	return (ret);
}

t_complex	pxl_to_cmplx(t_data *data, int x, int y)
{
	t_complex	c;

	// printf("%f in pxl to cmplx\n", data->screen.x_min);

	c.r = data->screen.x_min + (x / (double)WIN_X) \
	* (data->screen.x_max - data->screen.x_min);
	c.i = data->screen.y_min + (y / (double)WIN_Y) \
	* (data->screen.y_max - data->screen.y_min);
	// c.r = ((double)img->px_x - (double)screen->x_zero) * 3 / WIN_X;
	// c.i = ((double)screen->y_zero - (double)img->px_y) * 2 / WIN_Y;
	// printf("-----c.r: %f, c.i: %f in pxl to cmplx\n", c.r, c.i);
	return (c);
}