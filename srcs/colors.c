/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:56:26 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/30 16:49:09 by ialinaok         ###   ########.fr       */
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

t_trgb	set_trgb(float m, float r, float g, float b)
{
	t_trgb	rgb;
	
	rgb.r = (r + m) * 255;
	rgb.g = (g + m) * 255;
	rgb.b = (b + m) * 255;
	return (rgb);
}

t_trgb	hsv_to_rgb(float h, float s, float v)
{
	float	c;
	float	x;
	float	m;
	
	if (h > 360 || h < 0 || s > 100 || s < 0 || v > 100 || v < 0)
		return (set_trgb(0, 0, 0, 0));
	c = s / 100 * v / 100;
	x = c * (1 - abs(fmod(h/60.0, 2) - 1));
	m = v / 100 - c;
	if (h >= 0 && h < 60)
		set_trgb(m, c, x, 0);
	else if (h >= 60 && h < 120)
		set_trgb(m, x, c, 0);
	else if (h >= 120 && h < 180)
		set_trgb(m, 0, c, x);
	else if (h >= 180 && h < 240)
		set_trgb(m, 0, x, c);
	else if (h >= 240 && h < 300)
		set_trgb(m, x, 0, c);
	else
		set_trgb(m, c, 0, x);
	return (trgb);
}