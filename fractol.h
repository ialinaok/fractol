#ifndef FRACTOL
# define FRACTOL

# include "includes/mlx/mlx.h"
# include "includes/libft/libft.h"
# include "includes/ft_printf/libftprintf.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# include <stdio.h>

#define WIN_X 936	// 1300
#define WIN_Y 864	// 1200
#define MAX_ITER 255

typedef	struct	s_opti
{
	int	x_min_offset;
	int	x_max_offset;
	int	y_min_offset;
	int	y_max_offset;
}				t_opti;

typedef struct	s_coordi
{
	float	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}				t_coordi;

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		px_x;
	int		px_y;
}				t_img;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_coordi	screen;
	t_img		img;
	int			fractal_set;
	int			color_set;
}				t_data;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct	s_trgb
{
	int	t;
	int	r;
	int	g;
	int	b;
}			t_trgb;

/* utils.c */
void	show_error_msg(void);
void	show_usage(void);
int		find_set(char *argv, t_data *data);
int		find_color(char *argv2);
void	analyse_input(int argc, char **argv, t_data *data);
/* window.c */
int		key_hooks(int keycode, t_data *data);
void	pixel_put(t_data *data, int color);
int		close_x(t_data *data);
void	arrow_moves(int keycode, t_data *data);
void	put_image_to_image(void *dest, void *src, int x_offset, int y_offset);
/* zoom.c */
int	mouse_zoom(int button, int x, int y, t_data	*data);
/* render.c */
int	render(t_data *data);
int	get_started(t_data *data);
int	dumb_colors(void);
void	dumb_shit(t_data *data);
/* trgb.c */
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
/* colors.c */
int		paint_my_wrld(int iterations, t_data *data);
void	default_color(int iterations, t_trgb *trgb);
void	bernstein(int iterations, t_trgb *trgb);
void	blue(int iterations, t_trgb *trgb);
/* mandelbrot.c */
void		mandelbrot_init(t_data *data);
t_complex	mandelbrot_pxl_to_cmplx(t_data *data);
int			mandelbrot_iter(t_complex *c);
void		mandelbrot(t_data *data);
/* julia.c */
void	julia_init(t_data *data);
int	normal_julia_iter(t_complex *z, t_complex c);
void	normal_julia(t_data *data, double r, double i);
/* cmplx_math.c */
t_complex	multi_cmplx(t_complex z, t_complex c);
t_complex	add_cmplx(t_complex z, t_complex *c);
double		abs_of_cmplx(t_complex z);

#endif