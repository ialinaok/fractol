#include <stdio.h>
#include <math.h>

// typedef struct	s_trgb
// {
// 	int	t;
// 	int	r;
// 	int	g;
// 	int	b;
// }			t_trgb;

// typedef struct s_hsv
// {
// 	int	h;
// 	int	s;
// 	int	v;
// }			t_hsv;

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// int	get_t_bit(int trgb)
// {
// 	return ((trgb >> 24) & 0xFF);
// }

// int	get_r_bit(int trgb)
// {
// 	return ((trgb >> 16) & 0xFF);
// }

// int	get_g_bit(int trgb)
// {
// 	return ((trgb >> 8) & 0xFF);
// }

// int	get_b_bit(int trgb)
// {
// 	return (trgb & 0xFF);
// }

// /* VERSION ONE */

// int	set_trgb(float m, float r, float g, float b)
// {
// 	t_trgb	trgb;
// 	int		rgb;

// 	printf("---r: %f  g: %f  b: %f\n\n", r, g, b);

// 	trgb.r = (r + m) * 255;
// 	trgb.g = (g + m) * 255;
// 	trgb.b = (b + m) * 255;
// 	printf("r: %f  g:%f b: %f\n\n", r, g, b);
// 	rgb = create_trgb(0, r, g, b);
// 	return (rgb);
// }

// int	hsv_to_rgb(t_hsv hsv)
// {
// 	float	c;
// 	float	x;
// 	float	m;

// 	if (hsv.h > 360 || hsv.h < 0 || hsv.s > 100 || hsv.s < 0 || hsv.v > 100 || hsv.v < 0)
// 		return (set_trgb(0, 0, 0, 0));
// 	c = (float)hsv.s / 100 * (float)hsv.v / 100;
// 	x = c * (1 - fabs(fmod((float)hsv.h / 60.0, 2) - 1));
// 	m = (float)hsv.v / 100 - c;
// 	// printf("===== c: %f x: %f m: %f\n", c, x, m);
// 	if (hsv.h >= 0 && hsv.h < 60)
// 		return (set_trgb(m, c, x, 0));
// 	else if (hsv.h >= 60 && hsv.h < 120)
// 		return (set_trgb(m, x, c, 0));
// 	else if (hsv.h >= 120 && hsv.h < 180)
// 		return (set_trgb(m, 0, c, x));
// 	else if (hsv.h >= 180 && hsv.h < 240)
// 		return (set_trgb(m, 0, x, c));
// 	else if (hsv.h >= 240 && hsv.h < 300)
// 	{
// 		printf("===== c: %f x: %f m: %f\n", c, x, m);
// 		printf("-------%x\n", set_trgb(m, x, 0, c));
// 		return (23);
// 	}
// 	else
// 		return (set_trgb(m, c, 0, x));
// }

// /* VERSION 2 */

// int	hsv_to_rg(t_hsv hsv)
// {
// 	unsigned char region;
// 	unsigned char remainder;
// 	unsigned char p, q, t;

// 	region = hsv.h / 60;
// 	remainder = (hsv.h - (region * 60)) * 6;
// 	p = (hsv.v * (255 - hsv.s)) >> 8;
// 	q = (hsv.v * (255 - ((hsv.s * remainder) >> 8))) >> 8;
// 	t = (hsv.v * (255 - ((hsv.s * (255 - remainder)) >> 8))) >> 8;
// 	if (region == 0)
// 		return (create_trgb(0, hsv.v, t, p));
// 	else if (region == 1)
// 		return (create_trgb(0, q, hsv.v, p));
// 	else if (region == 2)
// 		return (create_trgb(0, p, hsv.v, t));
// 	else if (region == 3)
// 		return (create_trgb(0, p, q, hsv.v));
// 	else if (region == 4)
// 		return (create_trgb(0, t, p, hsv.v));
// 	else
// 		return (create_trgb(0, hsv.v, p, q));
// }

/* FROM ALISTAIR */

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_hsv
{
	int	h;
	int	s;
	int	v;
}			t_hsv;

static int	create_trgb(t_rgb rgb)
{
	int	r;
	int	g;
	int	b;

	r = rgb.r;
	g = rgb.g;
	b = rgb.b;
	printf("r: %x  g:%x b: %x\n\n", r, g, b);
	return (0 << 24 | r << 16 | g << 8 | b);
}

static t_rgb	make_t_rgb(int r, int g, int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
		printf("-----r: %x  g:%x b: %x\n\n", rgb.r, rgb.g, rgb.b);

	return (rgb);
}

typedef struct s_vals
{
	unsigned char	p;
	unsigned char	q;
	unsigned char	t;
}	t_vals;

int	hsv_to_rgb(t_hsv hsv)
{
	t_rgb			rgb;
	t_vals			vals;
	unsigned char	region;
	unsigned char	remainder;

	region = hsv.h / 43;
	remainder = (hsv.h - (region * 43)) * 6;
	vals.p = (hsv.v * (255 - hsv.s)) >> 8;
	vals.q = (hsv.v * (255 - ((hsv.s * remainder) >> 8))) >> 8;
	vals.t = (hsv.v * (255 - ((hsv.s * (255 - remainder)) >> 8))) >> 8;
	if (region == 0)
		rgb = make_t_rgb(hsv.v, vals.t, vals.p);
	else if (region == 1)
		rgb = make_t_rgb(vals.q, hsv.v, vals.p);
	else if (region == 2)
		rgb = make_t_rgb(vals.p, hsv.v, vals.t);
	else if (region == 3)
		rgb = make_t_rgb(vals.p, vals.q, hsv.v);
	else if (region == 4)
		rgb = make_t_rgb(vals.t, vals.p, hsv.v);
	else
	{
			printf("====r: %x  g:%x b: %x\n\n", hsv.v, vals.p, vals.q);
		rgb = make_t_rgb(hsv.v, vals.p, vals.q);
	}
	return (create_trgb(rgb));
}

int	main()
{
	int rgb_blah = 0x12a305;
	t_hsv	hsv;
	hsv.h = 221;
	hsv.s = 255;
	hsv.v = 255;
	int	new_rgb = hsv_to_rgb(hsv);
	printf("there we go: %x\n", new_rgb);
	return (0);
}

/* VERSION 4 */

// typedef struct {
//     double r;       // a fraction between 0 and 1
//     double g;       // a fraction between 0 and 1
//     double b;       // a fraction between 0 and 1
// } rgb;

// typedef struct {
//     double h;       // angle in degrees
//     double s;       // a fraction between 0 and 1
//     double v;       // a fraction between 0 and 1
// } hsv;

// rgb hsv_to_rgb(hsv in)
// {
//     double      hh, p, q, t, ff;
//     long        i;
//     rgb         out;

//     if(in.s <= 0.0) {       // < is bogus, just shuts up warnings
//         out.r = in.v;
//         out.g = in.v;
//         out.b = in.v;
//         return out;
//     }
//     hh = in.h;
//     if(hh >= 360.0) hh = 0.0;
//     hh /= 60.0;
//     i = (long)hh;
//     ff = hh - i;
//     p = in.v * (1.0 - in.s);
//     q = in.v * (1.0 - (in.s * ff));
//     t = in.v * (1.0 - (in.s * (1.0 - ff)));

//     switch(i) {
//     case 0:
//         out.r = in.v;
//         out.g = t;
//         out.b = p;
//         break;
//     case 1:
//         out.r = q;
//         out.g = in.v;
//         out.b = p;
//         break;
//     case 2:
//         out.r = p;
//         out.g = in.v;
//         out.b = t;
//         break;

//     case 3:
//         out.r = p;
//         out.g = q;
//         out.b = in.v;
//         break;
//     case 4:
//         out.r = t;
//         out.g = p;
//         out.b = in.v;
//         break;
//     case 5:
//     default:
//         out.r = in.v;
//         out.g = p;
//         out.b = q;
//         break;
//     }
//     return out;     
// }

// int	main()
// {
// 	int rgb_blah = 0x12a305;
// 	hsv	hsv;
// 	hsv.h = 221;
// 	hsv.s = 78;
// 	hsv.v = 92;
// 	rgb	new_rgb = hsv_to_rgb(hsv);
// 	int	int_rgb = create_trgb(0, new_rgb.r, new_rgb.g, new_rgb.b);
// 	printf("there we go: %x\n", int_rgb);
// 	return (0);
// }

