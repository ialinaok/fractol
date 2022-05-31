/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:56:26 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/31 22:42:46 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	bernstein(int iterations, t_trgb *trgb)
{
	float	x;

	x = (double)iterations / MAX_ITER;
	trgb->r = 9 * (1 - x) * pow(x, 3) * 255;
	trgb->g = 23 * pow((1 - x), 2) * pow(x, 2) * 255;
	trgb->b = 8.5 * pow((1 - x), 3) * x * 255;
	// trgb->r = 0xFF;
	// trgb->g = 0x00;
	// trgb->b = 0x00;
}

int	paint_my_wrld(int iterations, t_data *img)
{
	t_trgb	trgb;

	trgb.t = 0x00;
	if (img->color_scheme == -1) // default
	{
		trgb.r = 0x55;
		trgb.g = 0x35;
		trgb.b = 0x45;
	}
	else if (img->color_scheme == 0) // Bernstein
	{
		bernstein(iterations, &trgb);
	}
	return (create_trgb(trgb.t, trgb.r, trgb.g, trgb.b));
}
