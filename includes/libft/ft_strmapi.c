/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:12:14 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/23 10:35:20 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* applies the function ’f’ to each character of the string ’s’ , and passing 
 * its index as first argument to create a new string (with malloc()) resulting 
 * from successive applications of ’f’ */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	size_t	len;
	char	*newstr;

	i = 0;
	if (!s && !f)
		return (NULL);
	len = ft_strlen(s) + 1;
	newstr = (char *)malloc(len);
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	i = 0;
	while (newstr[i] != '\0')
	{
		newstr[i] = f(i, newstr[i]);
		i++;
	}
	return (newstr);
}
