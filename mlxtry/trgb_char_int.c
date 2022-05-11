/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_char_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:56:33 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/11 08:36:07 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int	add_shade(double distance, int color)
{
	int	add;
	int	t;
	unsigned char	r = get_r(color);
	unsigned char	g = get_g(color);
	unsigned char	b = get_b(color);

	add = 255;
	t = (int)round(distance * add);
	// printf("t %x     r %x    g %x     b %x\n", t, r, g, b);
	color = create_trgb(t, r, g, b);
	return (color);
}