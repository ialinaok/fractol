/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:24:33 by ialinaok          #+#    #+#             */
/*   Updated: 2022/02/22 17:56:44 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function outputs the character ’c’ to the given file descriptor */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
