/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:19:40 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/30 09:03:58 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot_init(t_coordi *screen)
{
	screen->x_min = -2;
	screen->x_max = 2;
	screen->y_min = -2;
	screen->y_max = 2;
	screen->x_zero = WIN_X / 2;
	screen->y_zero = WIN_Y / 2;
}

void	mandelbrot_pxl_to_cmplx(t_complex *c, t_coordi *screen, t_data *img)
{
	c->r = ((double)img->px_x - (double)screen->x_zero) * 4 / WIN_X;
	c->i = ((double)screen->y_zero - (double)img->px_y) * 4 / WIN_Y;
}

int	mandelbrot_iter(t_complex *c)
{
	int			i;
	t_complex	z;
	
	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	while (abs_of_cmplx(z) <= 2 && i < MAX_ITER)
	{
		z = add_cmplx(multi_cmplx(z, z), c);
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *img)
{
	t_complex	c;
	t_coordi	screen;
	int			i;
	int			color;

	img->px_y = 0;
	mandelbrot_init(&screen);
	while (img->px_y < WIN_Y)
	{
		
		img->px_x = 0;
		while (img->px_x < WIN_X)
		{
			mandelbrot_pxl_to_cmplx(&c, &screen, img);
			i = mandelbrot_iter(&c);
			color = paint_my_wrld(i);
			pixel_put(img, img->px_x, img->px_y, color);
			img->px_x++;
		}
		img->px_y++;
	}
}