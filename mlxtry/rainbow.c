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
	win_ptr = mlx_new_window(mlx_ptr, 5, 1000, "try");
	while (y <= 600)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, c);
		printf("x = %d,    y = %d,     c = %x\n", x, y, c);
		x++;
		if (x == 5)
		{
			x = 0;
			if (c == color.red)
				c = c + 0x000100; // adding green
			else if (c > color.red && c < color.yellow)
				c = c + 0x000100;
			else if (c == color.yellow)
				c = c - 0x010000; // removing red
			else if (c < color.yellow && c > color.green)
				c = c - 0x010000;
			else if (c == color.green)
			{
				printf("========before c = %x\n", c);
				c = c + 0x000001; //adding blue
				printf("========after c = %x\n", c);
				printf("ÿo wtf!\n");
			}
			else if (c > color.green && c < color.sea)
			{
				c = c + 0x000001;
				printf("ÿo wtfx2!\n");
			}
			else if (c == color.sea)
				c = c - 0x000100; // removing green
			else if (c < color.sea && c > color.blue)
			{
				c = c - 0x000100;
				printf("are you fck here!\n");
		}
			else if (c == color.blue)
				c = c + 0x010000; // adding red
			else if (c > color.blue && c < color.red)
				c = c + 0x010000;
			y++;
			// printf("x = %d,y = %d\n", x, y);
			mlx_pixel_put(mlx_ptr, win_ptr, 200, 600, color.sea);
			}
	}
	// mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, -250);
	mlx_loop(mlx_ptr);
}