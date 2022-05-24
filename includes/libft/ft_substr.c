/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:58:02 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/23 10:45:30 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function allocates (with malloc()) and returns a substring from the string ’s’
 * the substring begins at index ’start’ and is of maximum size ’len’ */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < len)
		substr = (char *) malloc(slen + 1);
	else
		substr = (char *) malloc(len + 1);
	if (!substr)
		return (NULL);
	if (slen >= start)
		ft_strlcpy(substr, &s[start], len + 1);
	else
		substr[0] = '\0';
	return (substr);
}

// int	main(void)
// {
// 	char	arr[] = "Nomadland";
// 	int	i = 5;
// 	size_t len = 4;
// 	char	*arr2;

// 	arr2 = ft_substr(arr, i, len);
// 	printf("the first string is: %s\n", arr);
// 	printf("the substring is: %s\n", arr2);
// 	free(arr2);
// 	return (0);
// }