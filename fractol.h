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
#define Y_SIERP 1104
#define X_SIERP 1104
#define MAX_ITER 40

typedef struct	s_trgb
{
	int	t;
	int	r;
	int	g;
	int	b;
}			t_trgb;

typedef struct	s_coordi
{
	double	x_min;
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
	t_trgb		trgb;
	double		f;
	int			fractal_set;
	int			color_set;
	int			width;
	int			length;
}				t_data;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

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
void	put_image_to_image(void *dest, void *src, int x_offset, int y_offset);
/* zoom.c */
int		mouse_zoom(int button, int x, int y, t_data	*data);
void	calc_distance(t_complex point, t_coordi *dist, t_data *data);
/* render.c */
int		render(t_data *data, int x, int y);
void	define_julias(t_data *data, t_complex *julia);
/* trgb.c */
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
/* colors.c */
int		paint_my_wrld(int iterations, t_data *data);
void	default_color(int iterations, t_data *data);
void	bernstein(int iterations, t_data *data);
void	blue(int iterations, t_data *data);
void	move_me(int iterations, t_data *data);
/* mandelbrot.c */
void		mandelbrot_init(t_data *data);
int			mandelbrot_iter(t_complex *c);
void		mandelbrot(t_data *data, int x, int y);
/* julia.c */
void	julia_init(t_data *data);
int		normal_julia_iter(t_complex *z, t_complex *c);
void	normal_julia(t_data *data, t_complex *c, double x, double y);
int		find_julia_set(char *argv1);
/* burning_ship.c */
void	burning_ship_init(t_data	*data);
int		burning_ship_iter(t_complex *c);
void	burning_ship(t_data *data, int x, int y);
/* sierpinsky.c */
void	sierpinsky(t_data *data);
void	draw_small_triangle(t_data *data, int x_y, int len);
void	draw_small_triangle_1(t_data *data, int x_y, int len);
void	draw_small_triangle_2(t_data *data, int x_y, int len);
/* lines.c */
void	draw_horizontal(t_data *data, int x, int y, int length);
void	draw_vertical(t_data *data, int x, int y, int length);
void	draw_diagonal(t_data *data, int x, int y, int length);
void	draw_big_triangle(t_data *data, int x_and_y, int x_diagonal, int len);
/* cmplx_math.c */
t_complex	multi_cmplx(t_complex z, t_complex c);
t_complex	add_cmplx(t_complex z, t_complex *c);
double		abs_of_cmplx(t_complex z);
t_complex	pxl_to_cmplx(t_data *data, int x, int y);
/* arrow.c */
void	arrow_moves(int keycode, t_data *data);
void	right_arrowkey(t_data *data, double x_range);
void	left_arrowkey(t_data *data, double x_range);
void	up_arrowkey(t_data *data, double y_range);
void	down_arrowkey(t_data *data, double y_range);
#endif