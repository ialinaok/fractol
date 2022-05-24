/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:14:17 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:55:34 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function fills the first n bytes of the memory area
 * pointed to by s with the constant byte c */

#include<stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*put;

	put = s;
	while (n > 0)
	{
		*put++ = c;
		n--;
	}
	return (s);
}

/*int main(void)
{
	char    str[5] = "Hola";
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		printf("%c", str[n]);
		n++;
	}
	printf("\n");
	ft_memset(str, 'M', sizeof(char) * 4);
	n = 0;
	while (str[n] != '\0')
	{
		printf("%c", str[n]);
		n++;
	}
	printf("\n");
	return (0);
}*/
