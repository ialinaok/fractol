/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:16:00 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:33:23 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function takes as a parameter an element and frees the memory of the 
 * element’s content using the function ’del’ given as a parameter 
 * and free the element
 * the memory of ’next’ is not be freed */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
