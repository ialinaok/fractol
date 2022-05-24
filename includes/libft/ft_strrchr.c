/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:09:56 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 18:04:04 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function returns a pointer to the last occurrence of the character c 
 * in the string */ 

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != '\0')
	{
		ptr++;
	}
	if (c == '\0')
	{
		return (ptr);
	}
	while (ptr != (str - 1))
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		ptr--;
	}
	return (NULL);
}

// int main(void)
// {
//     char    arr1[] = "bullshits";
//     char    arr2[] = "mascara";
//     char    *ptr1;
//     char    *ptr2;
//     char    *ptr3;

//     printf("address of 's' in arr1 is: %p\n", &arr1[8]);
//     printf("address of 'a' in arr2 is: %p\n", &arr2[6]);
//     ptr1 = ft_strrchr(arr1, 's');
//     printf("in arr1 2nd 's' was found at address: %p\n", ptr1);
//     ptr2 = ft_strrchr(arr2, 'a');
//     printf("in arr2 last 'a' was found at address: %p\n", ptr2);
//     ptr3 = ft_strrchr(arr1, 'a');
//     printf("return value of strchr: %c", *ptr3);
//     return (0);
// }
