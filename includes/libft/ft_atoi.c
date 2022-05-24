/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:34:25 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/23 11:33:29 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function converts the initial portion of the string pointed to by ptr to int
 * returns a converted value or 0 on error
 * ignores whitespaces before the number */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int	i;
	int	sign;
	int	count;

	i = 0;
	sign = 1;
	count = 0;
	while (ptr[i] == '\t' || ptr[i] == '\n' || ptr[i] == '\v'
		|| ptr[i] == '\f' || ptr[i] == '\r' || ptr[i] == ' ')
		i++;
	if ((ptr[i] == '-') || (ptr[i] == '+'))
	{
		sign = 44;
		sign = sign - ptr[i++];
	}
	while ((ptr[i] >= 48) && (ptr[i] <= 57))
		count = count * 10 + (ptr[i++] - '0');
	return (count * sign);
}

// int	main(void)
// {
// 	char	arr[] = "   -2147483647";
// 	int		r;

// 	r = ft_atoi(arr);
// 	printf("the int value of arr is: %d\n", r);
// 	return (0);
// }