#include <stdio.h>


unsigned char reverse_bit(unsigned char octet)
{
	unsigned char zero = 0;
	unsigned char ret = 0;
	int	m = 7;
	int	n = 0;
	while(m > 0)
	{
		ret = ret << m | (unsigned char)1 & octet;
		m--;
	}
	return (ret);
}

unsigned char	reverse(unsigned char octet)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 128;
	j = 1;
	while (i > 0)
	{
		if (octet / i == 1)
		{
			res += j;
			octet -= i;
		}
		j *= 2;
		i /= 2;
	}
	return (res);
}

int	main(void)
{
	unsigned char octet;
	unsigned char ret;

	octet = 234;
	ret = reverse_bit(octet);
	printf("octet: %d,\nret: %d\n", octet, ret);
	return (0);
}