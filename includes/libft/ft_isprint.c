/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:13:54 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:24:47 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function checks whether c is a printable character */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
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
// 	if (ft_isprint('\0') == 0)
// 	{
// 		printf("This is not a printable character \n");
// 	}
// 	else
// 	{
// 		printf("This is a printable character \n");
// 	}
// 	return (0);
// }
// //do I have to count for characters that are not possible to test like TAB
// //this function only takes int tho so irdk how