#include "mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

typedef struct _data
{
	unsigned int	red;
	unsigned int	yellow;
	unsigned int	green;
	unsigned int	sea;
	unsigned int	blue;
	unsigned int purple;
}	color;

void	init_color(color *color)
{
	color->red = 0xFF0000;
	color->yellow = 0xFFFF00;
	color->green = 0x00FF00;
	color->sea = 0x00FFFF;
	color->blue = 0x0000FF;
	color->purple = 0x00FFFF;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	color	color;
	int		x = 0;
	int		y = 0;
	unsigned int		c = 0xFF0000;

	init_color(&color);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 300, 1300, "try");
	while (y <= 1021)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, c);
		x++;
		if (x == 300)
		{
			x = 0;
			if (c == color.red)
				c = c + 0x000100; // adding green
			else if (c > color.red && c < color.yellow)
				c = c + 0x000100;
			else if (c == color.yellow)
				c = c - 0x010000; // removing red
			else if (c > color.green && c < color.sea)
				c = c + 0x000001; // 65281 - 65536 = -255
			else if (c == color.sea)
				c = c - 0x000100; // removing green
			else if (c < color.yellow && c > color.green)
				c = c - 0x010000;
			else if (c == color.green)
				c = c + 0x000001; //adding blue
			else if (c < color.sea && c > color.blue)
				c = c - 0x000100;
			else if (c == color.blue)
				c = c + 0x010000; // adding red
			y++;
		}
	}
	while (y > 1021 && y < 1300)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, c);
		x++;
		if (x == 300)
		{
			x = 0;
			if (c == color.blue)
				c = c + 0x010000; // adding red
			else if (c > color.blue && c < color.red)
				c = c + 0x010000;
			y++;
		}
	}
	mlx_loop(mlx_ptr);
}