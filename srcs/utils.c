/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:32:43 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/27 00:37:27 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	show_error_msg(void)
{
	ft_printf("\n>>>ERROR<<<\nuse --help to see instructions\n\n");
}

void	show_usage(void)
{
	ft_printf("\nThe correct usage: \n%% ./fractol <fractal set>\n\nsets to choose from:\
	\n- Mandelbrot\n- Julia\n\n");
}

// 0 for Mandelbrot
// 1 for Julia

int	find_set(char *argv)
{
	int	n;

	n = 0;
	char	*sets[2] = {"Mandelbrot", "Julia"};
	if (ft_strncmp(argv, "--help", 5) == 0)
		show_usage();
	while (n < 2)
	{
		if (ft_strncmp(argv, sets[n], 10) == 0)
			return (n);
		n++;
	}
	return (23);
}