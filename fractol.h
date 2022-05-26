#ifndef FRACTOL
# define FRACTOL

# include "includes/mlx/mlx.h"
# include "includes/libft/libft.h"
# include "includes/ft_printf/libftprintf.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

#define WIN_X 1000
#define WIN_Y 1000
#define MAX_ITER 255

typedef struct	s_ptr
{
	void	*mlx;
	void	*win;
}				t_ptr;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct	s_coordi
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		x_zero;
	int		y_zero;
}				t_coordi;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		px_x;
	int		px_y;
}				t_data;

/* utils.c */
void	show_error_msg(void);
void	show_usage(void);
int		find_set(char *argv);
/* window.c */
int		get_started(char *set);
int		close_window(int keycode, t_ptr *ptr);
void	pixel_put(t_data *img, int x, int y, int color);

#endif