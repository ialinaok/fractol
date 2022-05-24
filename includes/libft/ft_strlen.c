/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:05:36 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 18:29:56 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function calculates the length of the string s, excluding the terminating 
 * null byte */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

// int	main(void)
// {
// 	char	str[] = "Hi Alistair";

// 	printf("the length of the string is %ld \n", ft_strlen(&str[3]));
// 	return (0);
// }
