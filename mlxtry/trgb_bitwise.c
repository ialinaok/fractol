/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_bitwise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:52:01 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/09 18:12:10 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_trgb_bit(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t_bit(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r_bit(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g_bit(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b_bit(int trgb)
{
	return (trgb & 0xFF);
}