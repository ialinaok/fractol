/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:25:14 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:38:19 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function allocates (with malloc()) and returns a new element
 * the variable ’content’ is initialized with the value of the parameter ’content’
* the variable ’next’ is initialized to NULL */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
