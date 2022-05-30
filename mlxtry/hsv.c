#include <stdio.h>
#include <math.h>

typedef struct	s_trgb
{
	int	t;
	int	r;
	int	g;
	int	b;
}			t_trgb;

typedef struct s_hsv
{
	int	h;
	int	s;
	int	v;
}			t_hsv;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t_bit(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r_bit(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g_bit(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b_bit(int trgb)
{
	return (trgb & 0xFF);
}

int	set_trgb(float r, float g, float b)
{
	t_trgb	trgb;
	int		rgb;

	// printf("---r: %f  g: %f  b: %f\n\n", r, g, b);

	// trgb.r = (r + m) * 255;
	// trgb.g = (g + m) * 255;
	// trgb.b = (b + m) * 255;
	printf("r: %f  g:%f b: %f\n\n", r, g, b);
	rgb = create_trgb(0, r, g, b);
	return (rgb);
}

int	hsv_to_rgb(t_hsv hsv)
{
	// float	c;
	// float	x;
	// float	m;

	// if (hsv.h > 360 || hsv.h < 0 || hsv.s > 100 || hsv.s < 0 || hsv.v > 100 || hsv.v < 0)
	// 	return (set_trgb(0, 0, 0, 0));
	// c = (float)hsv.s / 100 * (float)hsv.v / 100;
	// x = c * (1 - fabs(fmod((float)hsv.h / 60.0, 2) - 1));
	// m = (float)hsv.v / 100 - c;
	// // printf("===== c: %f x: %f m: %f\n", c, x, m);
	// if (hsv.h >= 0 && hsv.h < 60)
	// 	return (set_trgb(m, c, x, 0));
	// else if (hsv.h >= 60 && hsv.h < 120)
	// 	return (set_trgb(m, x, c, 0));
	// else if (hsv.h >= 120 && hsv.h < 180)
	// 	return (set_trgb(m, 0, c, x));
	// else if (hsv.h >= 180 && hsv.h < 240)
	// 	return (set_trgb(m, 0, x, c));
	// else if (hsv.h >= 240 && hsv.h < 300)
	// {
	// 	printf("===== c: %f x: %f m: %f\n", c, x, m);
	// 	printf("-------%x\n", set_trgb(m, x, 0, c));
	// 	return (23);
	// }
	// else
	// 	return (set_trgb(m, c, 0, x));
	unsigned char region;
	unsigned char remainder;
	unsigned char p, q, t;

	region = hsv.h / 60;
	remainder = (hsv.h - (region * 60)) * 6;
	p = (hsv.v * (255 - hsv.s)) >> 8;
	q = (hsv.v * (255 - ((hsv.s * remainder) >> 8))) >> 8;
	t = (hsv.v * (255 - ((hsv.s * (255 - remainder)) >> 8))) >> 8;
	if (region == 0)
		return (set_trgb(hsv.v, t, p));
	else if (region == 1)
		return (set_trgb(q, hsv.v, p));
	else if (region == 2)
		return (set_trgb(p, hsv.v, t));
	else if (region == 3)
		return (set_trgb(p, q, hsv.v));
	else if (region == 4)
		return (set_trgb(t, p, hsv.v));
	else
		return (set_trgb(hsv.v, p, q));
}

int	main()
{
	int rgb = 0x12a305;
	t_hsv	hsv;
	hsv.h = 115;
	hsv.s = 97;
	hsv.v = 28;
	int	new_rgb = hsv_to_rgb(hsv);
	printf("there we go: %x\n", new_rgb);
	return (0);
}
