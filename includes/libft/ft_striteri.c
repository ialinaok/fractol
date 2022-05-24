/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:14:46 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 18:08:57 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* applies the function f to each character of the string passed as argument
 * and passing its index as first argument; each character is passed by
 * address to f to be modified if necessary */ 

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
