/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:15:53 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:18:11 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function checks for an alphanumeric character */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= '0' && c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int	main(void)
// {
// 	if (ft_isalnum('{') == 0)
// 	{
// 		printf("This is NOT a digit or alpha \n");
// 	}
// 	else
// 	{
// 		printf("This is a digit or alpha \n");
// 	}
// 	return (0);
// }
