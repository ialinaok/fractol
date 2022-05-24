/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 23:03:56 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/23 10:37:46 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function compares the two strings s1 and s2 and returns an integer less than,
 * equal to, or greater than zero if s1 is found, respectively, to be less than,
 * to match, or be greater than s2 */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		if ((*s1 == '\0') || (*s2 == '\0'))
		{
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	if (n == 0)
// 	{
// 		return (0);
// 	}
// 	while ((n > 0) && (*s1 != 0))
// 	{
// 		if (*s1 < *s2)
// 		{
// 			return ((unsigned char)*s1 - (unsigned char)*s2);
// 		}
// 		if (*s1 == *s2)
// 		{
// 			return ((unsigned char)*s1 - (unsigned char)*s2);
// 		}
// 		if (*s1 > *s2)
// 		{
// 			return ((unsigned char)*s1 - (unsigned char)*s2);
// 		}
// 		else
// 		{
// 			return (0);
// 		}
// 		n--;
// 		s1++;
// 		s2++;
// 	}
// }

// int	main(void)
// {
// 	char	arr[] = "something";
// 	char	arr2[] = "something";
// 	int		n;
// 	size_t	size;

// 	printf("size of unsigned char: %lu\n", sizeof(const unsigned char *));
// 	printf("size of const char*: %lu\n", sizeof(const char *));
// 	size = 9;
// 	printf("arr: %s\narr: %s\nsize is: %zu\n", arr, arr2, size);
// 	n = ft_strncmp(arr, arr2, size);
// 	printf("function return is: %d", n);
// 	return (0);
// }