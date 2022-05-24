/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:00:44 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 18:27:38 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function copies strings, takes the full size of the buffer (not just the 
 * length) and guarantees to NUL-terminate the result (as long as size is 
 * larger than 0; a byte for the NUL should be included in size
 * src must be NUL-terminated */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	int		n;

	src_len = ft_strlen(src);
	n = src_len;
	if (src_len + 1 < dst_size)
	{
		while ((n + 1) != 0)
		{
			*dst++ = *src++;
			n--;
		}
	}
	if ((src_len >= dst_size) && (dst_size != 0))
	{
		while ((dst_size - 1) != 0)
		{
			*dst++ = *src++;
			dst_size--;
		}
		dst[dst_size - 1] = '\0';
	}
	return (src_len);
}

// int main(void)
// {
// 	char arr_src[6] = "Julia";
// 	char arr_dst[5] = "Anna";
// 	int n = 0;
// 	int  src_size;

// 	printf("Source string is: ");
// 	while (arr_src[n] != '\0')
// 	{
// 		printf("%c", arr_src[n]);
// 		n++;
// 	}
// 	printf("\ndestination string is: ");
// 	n = 0;
// 	while (arr_dst[n] != '\0')
// 	{
// 		printf("%c", arr_dst[n]);
// 		n++;
// 	}
// 	printf("\nafter the use of ft_strlcpy strings are:\n");
// 	ft_strlcpy(arr_dst, arr_src, 0);
// 	n = 0;
// 	printf("source string is: ");
// 	while (arr_src[n] != '\0')
// 	{
// 		printf("%c", arr_src[n]);
// 		n++;
// 	}
// 	printf("\n");
// 	printf("destination string is: ");
// 	n = 0;
// 	while (arr_dst[n] != '\0')
// 	{
// 		printf("%c", arr_dst[n]);
// 		n++;
// 	}
// 	printf("\n");
// 	src_size = ft_strlcpy(arr_dst, arr_src, 0);
// 	printf("size of source string is: %d \n", src_size);
// 	return (0);
// }