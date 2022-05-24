/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:49:39 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/23 10:40:41 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function locates the	first occurrence of the	null-terminated string needle 
 * in the string big, where not more than n characters are searched
 * characters that appear after a `\0' character are not searched */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*occ;
	size_t	needle_len;
	int		i;

	i = 0;
	needle_len = ft_strlen(needle);
	occ = (char *) haystack;
	if (needle_len == 0)
		return (occ);
	if (needle_len > ft_strlen(haystack))
		return (NULL);
	while (needle_len + i <= n)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
				return (&occ[i]);
		}
		i++;
	}
	return (NULL);
}


// int	main(void)
// {
// 	char	arr1[] = "Nomadland";
// 	char	arr2[] = "land";
// 	char	*r;

// 	printf("strings are: s1 = '%s';\ns2 = '%s'\n", arr1, arr2);
// 	r = strnstr(arr1, arr2, 8);
// 	printf("the address of 'l' in s1 is: %p\n", &arr1[5]);
// 	printf("the address of s1 is: %p\n", arr1);
// 	printf("the return value is: %p", r);
// 	return (0);
// }