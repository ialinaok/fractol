/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:47:47 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:57:30 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function outputs the integer ’n’ to the given file descriptor */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	intprint;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			ft_putnbr_fd(147483648, fd);
			return ;
		}
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	intprint = n % 10 + '0';
	write(fd, &intprint, 1);
}
