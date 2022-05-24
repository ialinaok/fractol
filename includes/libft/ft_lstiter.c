/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:42:31 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:34:36 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function iterates the list ’lst’ and applies the function ’f’ to the 
 * content of each element */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst != NULL)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
