/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:28:12 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:28:32 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function allocates (with malloc()) and returns a string representing 
 * the integer received as an argument
 * negative numbers are handled */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;
	int	minus;

	if (n == -2147483648)
		return (11);
	minus = 0;
	if (n < 0)
	{
		n *= -1;
		minus = 1;
	}
	if (n < 10 && n >= 0)
		return (1 + minus);
	if (n >= 10)
	{
		count = count_digits(n / 10);
		return (1 + count + minus);
	}
	return (0);
}

static int	put_nbr(char *str, int n, int i)
{
	if (n < 0)
	{
		str[i] = '-';
		i++;
		if (n == -2147483648)
		{
			str[i] = '2';
			i++;
			i = put_nbr(str, 147483648, i);
		}
		n *= -1;
	}
	if (n >= 10)
		i = put_nbr(str, n / 10, i);
	str[i] = n % 10 + '0';
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = count_digits(n);
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	put_nbr(str, n, i);
	str[count] = '\0';
	return (str);
}

// int main(void)
// {
//   int n;
//   char  *arr;

//   n = -58778;
//   arr = ft_itoa(n);
//   printf("this is n: %s\n", arr);
//   free (arr);
//   return (0);
// }