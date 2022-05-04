#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x = 0;
	int		y = 0;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "try");
	while (y <= 500)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFB6C1);
		x++;
		if (x == 500)
		{
			x = 0;
			y++;
		}
	}
	mlx_loop(mlx_ptr);
}