/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:43:04 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 18:27:46 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function concatenates strings and takes the full size of the buffer (not just
 * the length) and guarantees to NUL-terminate the result (as long as there is 
 * at least one byte free in dst); a byte for the NUL should be included in size
 * both src and dst must be NUL-terminated */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		n;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	n = size;
	while ((n != 0) && (*dst != '\0'))
	{
		dst++;
		n--;
	}
	if (n == 0)
	{
		return (size + src_len);
	}
	while (((n - 1) != 0) && (*src != '\0'))
	{
		*dst++ = *src++;
		n --;
	}
	*dst = '\0';
	return (dst_len + src_len);
}

// int main(void)
// {
//   char dst[12] = "hello";
//   char src[7] = " world";
//   int   size;
//   size_t r;
//   size_t d;
//   size_t s;
//   size = 8;
//   printf("the dst string is %s\n", dst);
//   d = strlen(dst);
//   s = strlen(src);
//   printf("strlen(dst) = %zu\n", d);
//   printf("strlen(src) = %zu\n", s);
//   r = ft_strlcat(dst, src, size);
//   printf("after modification: '%s'; returned size is %zu\n", dst, r);
//   printf("size is: %d\n", size);
//   return (0);
// }