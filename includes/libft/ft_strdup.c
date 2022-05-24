/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:06:49 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 18:05:56 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function returns a pointer to a new string which is a duplicate of the 
 * string s; memory for the new string is allocated with malloc() */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*ptr;
	char	*ret;

	str = (char *)s;
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	ret = ptr;
	while (*str != '\0')
	{
		*ptr = *str;
		ptr++;
		str++;
	}
	*ptr = *str;
	return (ret);
}

// int	main(void)
// {
// 	char	str[] = "is this too much?";
// 	int i = 0;
// 	char	*ret;
// 	char	*out;

// 	printf("this is the initial string: %s\n", str);
// 	printf("this is what's stored at the returned address: ");
// 	out = ret = ft_strdup(str);
// 	while (*ret != '\0')
// 	{
// 		printf("%c", *ret);
// 		ret++;
// 		i++;
// 	}
// 	free(out);
// 	return (0);
// }