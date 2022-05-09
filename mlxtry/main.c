/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:20:24 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/09 18:58:08 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	unsigned char	t = 0x00;
	unsigned char	r = 0xFF;
	unsigned char	g = 0x45;
	unsigned char	b = 0xb1;
	int		x = 0;
	int		y = 0;
	int		trgb = 0;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 510, "main");
	img.img = mlx_new_image(mlx_ptr, 500, 510);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	trgb = create_trgb(t, r, g, b);
	while (y < 255)
	{
		printf("%x\n", t);
		pixel_put(&img, x, y, trgb);
		x++;
		if (x == 500)
		{
			t = get_t(trgb);
			t = t + 1;
			trgb = create_trgb(t, r, g, b);
			x = 0;
			y++;
		}
	}
	while (y < 510)
	{
		pixel_put(&img, x, y, trgb);
		x++;
		if (x == 500)
		{
			t = (float)get_t(trgb);
			t = t - 1;
			trgb = create_trgb((unsigned char)t, r, g, b);
			x = 0;
			y++;
		}
	}

	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}