/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:20:24 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/17 09:40:04 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

typedef	struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


int	close( void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	return (0);
}


int	main(void)
{
	t_vars	vars;
	t_data	img;
	unsigned char	t = 0x00;
	unsigned char	r = 0xFF;
	unsigned char	g = 0x45;
	unsigned char	b = 0xb1;
	int		x = 0;
	int		y = 0;
	int		trgb = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 510, "main");
	img.img = mlx_new_image(vars.mlx, 500, 510);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	trgb = create_trgb(t, r, g, b);
 /* creating opacity by extracting t, changing it's value +1
 and merging again */

	// while (y < 255)
	// {
	// 	printf("%x\n", t);
	// 	pixel_put(&img, x, y, trgb);
	// 	x++;
	// 	if (x == 500)
	// 	{
	// 		t = get_t(trgb);
	// 		t = t + 1;
	// 		trgb = create_trgb(t, r, g, b);
	// 		x = 0;
	// 		y++;
	// 	}
	// }
	// while (y < 510)
	// {
	// 	pixel_put(&img, x, y, trgb);
	// 	x++;
	// 	if (x == 500)
	// 	{
	// 		t = (float)get_t(trgb);
	// 		t = t - 1;
	// 		trgb = create_trgb((unsigned char)t, r, g, b);
	// 		x = 0;
	// 		y++;
	// 	}
	// }
/*  creating opacity by using add shade function */

	double dist = 0;
	while (y < 510)
	{
		pixel_put(&img, x, y, trgb);
		x++;
		if (x == 500)
		{
			printf("%x\n", trgb);
			x = 0;
			dist += 1;
			trgb = add_shade(dist, trgb);
			y += 2;
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, ON_KEYUP, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
