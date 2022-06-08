/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:32:43 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/08 05:13:11 by apielasz         ###   ########.fr       */
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
	\n- Mandelbrot\n- Julia_elegant\n- Julia_chineese\n- Julia_snowflake\n- Julia_medusa\n\
	- Julia_detail\n- Burning_ship\n\n");
	ft_printf("Optional usage: %% ./fractol <fractal set> <color mode>\n\ncolor modes to choose from:\
	\n- Spacey\n- Blue\n- Move_me\n\n");
	exit(0);
}

// 0 for Mandelbrot
// 1 for Julia

int	find_set(char *argv1, t_data *data)
{
	if (ft_strncmp(argv1, "--help", 5) == 0)
		show_usage();
	else if (ft_strncmp(argv1, "Mandelbrot", 10) == 0)
	{
		mandelbrot_init(data);
		return (0);
	}
	else if (ft_strncmp(argv1, "Julia", 5) == 0)
	{
		julia_init(data);
		return (find_julia_set(argv1));
	}
	else if (ft_strncmp(argv1, "Burning_ship", 12) == 0)
	{
		burning_ship_init(data);
		return (6);
	}
	else if (ft_strncmp(argv1, "Sierpinsky", 10) == 0)
		return (7);
	else
		show_usage();
	return (-1);
}

int	find_color(char *argv2)
{
	if (ft_strncmp(argv2, "Spacey", ft_strlen(argv2)) == 0)
		return (0);
	else if (ft_strncmp(argv2, "Blue", ft_strlen(argv2)) == 0)
		return (1);
	else if (ft_strncmp(argv2, "Move_me", 7) == 0)
		return (2);
	else
		return (-1);
}

void	analyse_input(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		show_error_msg();
	data->color_set = -1;
	if (argv[1])
		data->fractal_set = find_set(argv[1], data);
	if (argv[2])
		data->color_set = find_color(argv[2]);
}
