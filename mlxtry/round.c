#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h>

typedef	struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	double	x = 00;
	double	y = 0;
	// int		blue = 0xF0;
	// int		peach = 0xFFE5B4;
	int		pink = 0xFFB6C1;
	// int		orange = 0xFFB900;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 400, "str");
	img.img = mlx_new_image(mlx_ptr, 500, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < 500)
	{
		y = 100 * sin(10 * x);
		printf("1: %f\n", y);
		my_mlx_pixel_put(&img, x, y, pink);
		pink = pink + 0xf0bc;
		x = x + 0.1;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}