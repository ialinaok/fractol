/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:24:47 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 18:03:43 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function returns a pointer to the first occurrence of the character c 
 * in the string */ 

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != '\0')
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		ptr++;
	}
	if (*ptr == c)
	{
		return (ptr);
	}
	return (NULL);
}

// int main(void)
// {
//     char    arr1[] = "bullshit";
//     char    arr2[] = "mascara";
//     char    *ptr1;
//     char    *ptr2;
//     char    *ptr3;

//     printf("address of 's' in arr1 is: %p\n", &arr1[4]);
//     printf("address of 's' in arr2 is: %p\n", &arr2[2]);
//     ptr1 = ft_strchr(arr1, 's');
//     printf("in arr1 's' was found at address: %p\n", ptr1);
//     ptr2 = ft_strchr(arr2, 's');
//     printf("in arr2 's' was found at address: %p\n", ptr2);
//     ptr3 = ft_strchr(arr1, 'a');
//     printf("return value of strchr: %c", *ptr3);
//     return (0);
// }