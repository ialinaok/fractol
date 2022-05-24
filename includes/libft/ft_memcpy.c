/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:39:15 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:50:43 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function copies n bytes from memory area src to memory area dest
 * the memory areas must not overlap */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*put_dest;
	const char		*put_src;

	put_dest = dest;
	put_src = src;
	while (n > 0 && (dest != NULL || src != NULL))
	{
		*put_dest++ = *put_src++;
		n--;
	}
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char arr[] = "buffer n leftover";
	int n = 0;

	while (arr[n] != '\0')
	{
		printf("%c", arr[n]);
		n++;
	}
	ft_memcpy(arr, &arr[8], 10);
	n = 0;
	printf("\n");
	while (arr[n] != '\0')
	{
		printf("%c", arr[n]);
		n++;
	}
	//to see it overlaps memory
	// char str[] = "Live well!";
	// n = 0;
	// printf("%s\n", str);
	// ft_memcpy(&str[3], &str[2], 4);
	// printf("%s\n", str);
	// return (0);
}