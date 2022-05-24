/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:22:06 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/23 10:43:55 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function allocates (with malloc())) and returns a copy of ’s1’ with the
 * characters specified in ’set’ removed from the beginning and the end of 
 * the string */

#include "libft.h"

static int	find_end(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i >= 0 && s2[j] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				i--;
				break ;
			}
			if (s1[i] != s2[j])
				j++;
		}
	}
	return (i);
}

static int	find_start(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				i++;
				break ;
			}
			if (s1[i] != s2[j])
				j++;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start;
	char	*trim;
	int		i;

	i = 0;
	start = find_start(s1, set);
	len = find_end(s1, set) - start + 2;
	if (!s1)
		return (NULL);
	if (len > 0)
		trim = (char *)malloc(len);
	if (len <= 0)
		trim = (char *)malloc(1);
	if (!trim)
		return (NULL);
	while (len > 1)
	{
		trim[i++] = s1[start++];
		len--;
	}
	trim [i] = '\0';
	return (trim);
}

// int	main(void)
// {
// 	char	arr1[] = "   \t \n\n\nHello \t  Please\n Trim me !\n   \n  ";
// 	char	set[] = " \n\t";
// 	char	*trim;

// 	trim = ft_strtrim(arr1, set);
// 	printf("%s", trim);
// 	free(trim);
// 	return (0);
// }
