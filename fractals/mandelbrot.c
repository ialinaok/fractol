/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:19:40 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/26 21:11:06 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_coordi	mandelbrot_init(t_ptr *ptr, t_data *img)
{
	t_coordi	screen;

	screen.x_min = -2;
	screen.x_max = 2;
	screen.y_min = -2;
	screen.y_max = 2;
	screen.x_zero = WIN_X / 2;
	screen.y_zero = WIN_Y / 2;
}

void	mandelbrot_pxl_to_cmplx(t_complex *z, t_coordi *screen, t_data *img)
{
	z->r = (img->px_x - screen->x_zero) * 4 / WIN_X;
	z->i = (screen->y_zero - img->px_y) * 4 / WIN_Y;
}

void	mandelbrot_iter(t_complex *z)
{
	int	i;

	i = 0;
	while (abs_of_cmplx(z) <= 2 && i < MAX_ITER)
	{
		z = 
	}
}

void	mandelbrot(t_ptr *ptr, t_data *img)
{
	t_complex	z;
	t_coordi	screen;
	int			i;

	img->px_x = 0;
	img->px_y = 0;
	screen = mandelbrot_init(ptr, img);
	while (img->px_y < 1000)
	{
		mandelbrot_pxl_to_cmplx(&z, &screen);
		mandelbrot_iter(&z)
		if (img->px_x == 1000)
		{
			img->px_x = 0;
			
		}
	}
}