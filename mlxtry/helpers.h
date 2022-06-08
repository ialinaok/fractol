/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:06:50 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/07 20:40:59 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS
# define HELPERS

# include "mlx/mlx.h"
# include <stdio.h>
# include <math.h>

// typedef	struct s_img
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_img;

// void	pixel_put(t_data *data, int x, int y, int color);
int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);
int	add_shade(double distance, int color);

#endif