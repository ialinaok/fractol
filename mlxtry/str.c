#include "mlx/mlx.h"

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
	int		x = 10;
	int		y = 10;
	int		a = 490;
	int		b = 490;
	int		blue = 0xF0;
	int		peach = 0xFFE5B4;
	int		pink = 0xFFB6C1;
	int		orange = 0xFFB900;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "str");
	img.img = mlx_new_image(mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (a > 2)
	{
		y = 10;
		x = 10;
		while (y < a)
		{
			my_mlx_pixel_put(&img, x, y, pink);
			y++;
		}
		while (x < b)
		{
			my_mlx_pixel_put(&img, x, y, orange);
			x++;
		}
		y = 10;
		x = 10;
		while (x < b)
		{
			my_mlx_pixel_put(&img, x, y, peach);
			x++;
		}
		while (y < a + 1)
		{
			my_mlx_pixel_put(&img, x, y, blue);
			y++;
		}
		a = a / 1.1;
		b = b / 1.1;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}