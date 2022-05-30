/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:56:26 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/30 15:59:41 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	paint_my_wrld(int iterations)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0x00;
	if (iterations == MAX_ITER)
	{
		r = 0xFF;
		g = 0xFF;
		b = 0xFF;
	}
	else
	{
		r = 0xFF;
		g = 0x45;
		b = 0xB1;
	}
	return (create_trgb(t, r, g, b));
}

void	hsv_to_rgb(float h, float s, float v)
{
	float	x;
	t_trgb	trgb;
	
	if (h > 360 || h < 0 || s > 100 || s < 0 || v > 100 || v < 0)
		return ;
	x = s / 100 * v / 100 * (1 - abs(fmod(h/60.0, 2) - 1));
	if (h >= 0 && h < 60)
		r = 
}