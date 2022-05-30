/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmplx_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:25:01 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/30 08:59:36 by apielasz         ###   ########.fr       */
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