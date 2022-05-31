#ifndef FRACTOL
# define FRACTOL

# include "includes/mlx/mlx.h"
# include "includes/libft/libft.h"
# include "includes/ft_printf/libftprintf.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

#define WIN_X 1300
#define WIN_Y 1200
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
	int		color_scheme;
}				t_data;

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
int		find_set(char *argv);
int	find_color(char *argv2);
/* window.c */
int		get_started(int set, int color);
int		close_window(int keycode, t_ptr *ptr);
void	pixel_put(t_data *img, int x, int y, int color);
/* trgb.c */
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
/* colors.c */
int	paint_my_wrld(int iterations, t_data *img);
void	bernstein(int iterations, t_trgb *trgb);
/* math.c */
t_complex	multi_cmplx(t_complex z, t_complex c);
t_complex	add_cmplx(t_complex z, t_complex *c);
double		abs_of_cmplx(t_complex z);
/* mandelbrot.c */
void	mandelbrot_init(t_coordi *screen);
t_complex	mandelbrot_pxl_to_cmplx(t_coordi *screen, t_data *img);
int		mandelbrot_iter(t_complex *c);
void	mandelbrot(t_data *img);

#endif