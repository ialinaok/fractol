/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:05:58 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:19:39 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function checks for alphabetic character */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
// 	if (ft_isalpha('A') == 0)
// 	{
// 		printf("This is not alphabet \n");
// 	}
// 	else
// 	{
// 		printf("This is alphabet \n");
// 	}
// 	return (0);
// }
