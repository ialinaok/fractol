/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:12:27 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 16:14:46 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function allocates memory for an array of nmemb elements of size bytes each
 * returns a pointer to allocated memory or NULL if allocation fails
 * memory is set to zero */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	ptr = (char *)malloc(nelem * elsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nelem * elsize);
	return (ptr);
}
