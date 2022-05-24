/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:52:11 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:37:01 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* fucntion iterates the list ’lst’ and applies the function ’f’ to the content 
 * of each element; creates a new list resulting of the successive applications 
 * of the function ’f’; the ’del’ function is used to delete the content of an 
 * element if needed */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew((t_list *)f(lst->content));
	if (!new)
		return (NULL);
	first = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = ft_lstnew((t_list *)f(lst->content));
		if (!new->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		new = new->next;
	}
	return (first);
}
