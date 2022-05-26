/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:25:01 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/26 21:11:34 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	abs_of_cmplx(t_complex *z)
{
	return (sqrt(pow(z->r, 2) + pow(z->i, 2)));
}

double	add_cmplx(t_complex *z)
{
	
}