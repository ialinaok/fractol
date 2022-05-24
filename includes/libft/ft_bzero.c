/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:39:55 by ialinaok          #+#    #+#             */
/*   Updated: 2022/05/24 11:36:50 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function erases n bytes of memory starting at location pointed to by s */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*put;

	put = s;
	while (n > 0)
	{
		*put++ = '\0';
		n--;
	}
}
