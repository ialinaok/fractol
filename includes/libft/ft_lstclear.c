/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:29:34 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:32:21 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function deletes and frees the given element and every successor of that 
 * element, using the function ’del’ and free()
 * the pointer to the list is set to NULL */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*first;
	t_list	*next;

	if (lst && del)
	{
		next = *lst;
		while (next != NULL)
		{
			first = next;
			next = next->next;
			del(first->content);
			free(first);
		}
		*lst = NULL;
	}
}
