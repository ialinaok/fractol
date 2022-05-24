/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:13:39 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 18:10:50 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function allocates (with malloc()) and returns a new string, which is the 
 * result of the concatenation of ’s1’ and ’s2’ */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;

	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (*s1)
	{
		newstr[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		newstr[i] = *s2++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// int	main(void)
// {
// 	char	arr1[] = "I can think ";
// 	char	arr2[] = "of a way";
// 	char	*new;

// 	new = ft_strjoin(arr1, arr2);
// 	printf("this is s1: %s\n", arr1);
// 	printf("this is s2: %s\n", arr2);
// 	printf("this is new string: %s\n", new);
// 	free(new);
// 	return (0);
// }