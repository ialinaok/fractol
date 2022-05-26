/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:56:26 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/27 00:03:34 by apielasz         ###   ########.fr       */
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
		r = 0x00;
		g = 0x00;
		b = 0x00;
	}
	else
	{
		r = 0xFF;
		g = 0x45;
		b = 0xB1;
	}
	return (create_trgb(t, r, g, b));
}