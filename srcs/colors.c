/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:56:26 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/01 18:57:18 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	default_color(int iterations, t_trgb *trgb)
{
	float x;

	x = (double)iterations / MAX_ITER;
	trgb->r = 9 * (1 - x) * pow(x, 3) * 255 + 100;
	trgb->g = 23 * pow((1 - x), 2) * pow(x, 2) * 255;
	trgb->b = 8.5 * pow((1 - x), 3) * x * 255 + 40;
	trgb->t = (1 - x) * 60;
}

void	bernstein(int iterations, t_trgb *trgb)
{
	float	x;

	x = (double)iterations / MAX_ITER;
	trgb->r = 40 * (1 - x) * pow(x, 3) * 255;
	trgb->g = 3 * pow((1 - x), 2) * pow(x, 2) * 255;
	trgb->b = 7 * pow((1 - x), 3) * x * 255;
}

void	blue(int iterations, t_trgb *trgb)
{
	float x;

	x = (double)iterations / MAX_ITER;
	trgb->r = 9 * (1 - x) * pow(x, 3) * 255;
	trgb->g = 23 * pow((1 - x), 2) * pow(x, 2) * 255;
	trgb->b = 8.5 * pow((1 - x), 3) * x * 255;
}

int	paint_my_wrld(int iterations, t_data *img)
{
	t_trgb	trgb;

	trgb.t = 0x00;
	if (img->color_scheme == -1) // default
		default_color(iterations, &trgb);
	else if (img->color_scheme == 0) // Bernstein
		bernstein(iterations, &trgb);
	else if (img->color_scheme == 1)
		blue(iterations, &trgb);
	return (create_trgb(trgb.t, trgb.r, trgb.g, trgb.b));
}
