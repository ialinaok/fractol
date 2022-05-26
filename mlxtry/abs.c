#include <math.h>
#include <stdio.h>

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

double	abs_of_complex(t_complex *complex)
{
	double	abs_complex;

	return (abs_complex = sqrt(pow(complex->r, 2) + pow(complex->i, 2)));
}

double	abs_cpl(t_complex *complex)
{
	double	pow1;
	double	pow2;

	pow1 = complex->r * complex->r;
	pow2 = complex->i * complex->i;
	return (sqrt(pow1 + pow2));
}

int	main(void)
{
	t_complex	one;
	t_complex	two;

	one.r = -0.25;
	one.i = -2;
	two.r = 3;
	two.i = -4;
	printf("the first one:  %f %f\n", abs_of_complex(&one), abs_of_complex(&two));
	printf("the second one: %f %f\n", abs_cpl(&one), abs_cpl(&two));
}