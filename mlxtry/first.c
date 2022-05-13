#include "mlx/mlx.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(void)
{
	ft_putchar('x');
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x = 0;
	int		y = 0;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "try");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	while (y <= 500)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF - 0xFF0000);
		x++;
		if (x == 500)
		{
			x = 0;
			y++;
		}
	}
	mlx_loop(mlx_ptr);
}