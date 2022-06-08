/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_bye.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:43:49 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/07 19:52:02 by apielasz         ###   ########.fr       */
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
	ON_MOUSE_ENTER = 7,
	ON_MOUSE_LEAVE = 8,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int	enter(int x, int y, t_vars *vars)
{
	mlx_mouse_get_pos(vars->win, &x, &y);
	if (x >= 50 && x <= 250 && y >= 50 && y <= 250)
		mlx_mouse_hide();
	return (0);
}

int	leave(int x, int y, t_vars *vars)
{
	mlx_mouse_get_pos(vars->win, &x, &y);
	if (x >= 0 && x < 50 && y >= 0 && y < 50)
		mlx_mouse_hide();
	return (0);
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
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
	vars.win = mlx_new_window(vars.mlx, 300, 300, "hello_bye");
	img.img = mlx_new_image(vars.mlx, 300, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	trgb = create_trgb(t, r, g, b);
	int	d = 299;
	while (y < 300)
	{
		pixel_put(&img, x, y, trgb);
		x++;
		if (x == 300)
		{
			x = d;
			t = get_t(trgb);
			t += 1;
			trgb = create_trgb(t, r, g, b);
			y++;
			d--;
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, close, &vars);
	// mlx_loop_hook(vars.win, enter, &vars);
	// mlx_hook(vars.win, 6, 1L<<4, enter, &vars);
	// mlx_loop_hook(vars.win, leave, &vars);
	mlx_loop(vars.mlx);
}