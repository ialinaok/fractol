/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:50:01 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/23 10:47:55 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function converts the letter c to upper case, if possible */

int	ft_toupper(int c)
{
	int		u;

	if ((c >= 97) && (c <= 122))
	{
		u = c - 32;
		return (u);
	}
	else
	{
		return (c);
	}
}

// int main(void)
// {
//     int a = 'a';
//     int b = 'p';
//     int c = 'z';
//     int d = '!';
//     int e = 123;

//     printf("a --> %c\n", ft_toupper(a));
//     printf("p --> %c\n", ft_toupper(b));
//     printf("z --> %c\n", ft_toupper(c));
//     printf("! --> %d, %c\n", ft_toupper(d), ft_toupper(d));
//     printf("123 --> %d\n", ft_toupper(e));
//     return (0);
// }
