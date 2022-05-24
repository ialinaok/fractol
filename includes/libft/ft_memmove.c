/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:18:39 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:52:00 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function copies n bytes from memory area src to memory area dest
 * the memory areas may overlap */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*put_dest;
	const char		*put_src;

	put_dest = dest;
	put_src = src;
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			put_dest[i] = put_src[i];
			i--;
		}
	}
	else
	{
		while (n > 0 && (dest != NULL || src != NULL))
		{
			*put_dest++ = *put_src++;
			n--;
		}
	}
	return (dest);
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*put_dest;
// 	unsigned char	temp[n];
// 	const char		*put_src;
// 	size_t			i;

// 	i = 0;
// 	put_dest = dest;
// 	put_src = src;
// 	while (i != n && (dest != NULL || src != NULL))
// 	{
// 		temp[i] = *put_src++;
// 		i++;
// 	}
// 	i = 0;
// 	while (i != n && (dest != NULL || src != NULL))
// 	{
// 		*put_dest++ = temp[i];
// 		i++;
// 	}
// 	return (dest);
// }

// int main(void)
// {
// 	char arr [5] = "Hola";
// 	int n = 0;
// 	while (arr[n] != '\0')
// 	{
// 		printf("%c", arr[n]);
// 		n++;
// 	}
// 	printf("\n");
// 	ft_memmove(arr, &arr[2], 2);
// 	n = 0;
// 	printf("%d\n", sizeof(unsigned char *));

// 	while (arr[n] != '\0')
// 	{
// 		printf("%c", arr[n]);
// 		n++;
// 	}
// 	return (0);
// }