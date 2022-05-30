#include <stdio.h>

int	find_max(int r, int g, int b)
{
	if (r > g)
	{
		if (r > b)
			return (r);
		else
			return (b);
	}
	else if (g > b)
		return (g);
	else
		return (b);
	return (0);
}

int	find_min(int r, int g, int b)
{
	if (r < g)
	{
		if (r < b)
			return (r);
		else
			return (b);
	}
	else if (g < b)
		return (g);
	else
		return (b);
	return (0);
}

int	main(void)
{
	int	r = 2;
	int	g = 42;
	int	b = 6667;

	printf("the biggest: %d\n", find_max(r, g, b));
	printf("the smallest: %d\n", find_min(r, g, b));
	return (0);
}