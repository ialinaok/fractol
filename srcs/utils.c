/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:32:43 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/01 18:58:46 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	show_error_msg(void)
{
	ft_printf("\n>>>ERROR<<<\nuse --help to see instructions\n\n");
	exit(0);
}

void	show_usage(void)
{
	ft_printf("\nThe correct usage: \n%% ./fractol <fractal set>\n\nsets to choose from:\
	\n- Mandelbrot\n- Julia\n\n");
	ft_printf("Optional usage: %% ./fractol <fractal set> <color mode>\n\ncolor modes to choose from:\
	\n- Spacey\n- Blue\n\n");
	exit(0);
}

// 0 for Mandelbrot
// 1 for Julia

int	find_set(char *argv1)
{
	int	n;

	n = 0;
	char	*sets[2] = {"Mandelbrot", "Julia"};
	if (ft_strncmp(argv1, "--help", 5) == 0)
		show_usage();
	while (n < 2)
	{
		if (ft_strncmp(argv1, sets[n], 10) == 0)
			return (n);
		n++;
	}
	return (23);
}

int	find_color(char *argv2)
{
	int	n;

	n = 0;
	char	*sets[2] = {"Spacey", "Blue"};
	while (n < 2)
	{
		if (ft_strncmp(argv2, sets[n], 10) == 0)
			return (n);
		n++;
	}
	return (23);
}
