/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:44:56 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/08 03:57:57 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	find_julia_set(char *argv1)
{
	if (ft_strncmp(argv1, "Julia_elegant", 14) == 0)
		return (1);
	else if (ft_strncmp(argv1, "Julia_chineese", 14) == 0)
		return (2);
	else if (ft_strncmp(argv1, "Julia_snowflake", 15) == 0)
		return (3);
	else if (ft_strncmp(argv1, "Julia_medusa", 12) == 0)
		return (4);
	else if (ft_strncmp(argv1, "Julia_detail", 12) == 0)
		return (5);
	else
		show_usage();
	return (-1);
}

void	julia_init(t_data *data)
{
	data->screen.x_min = -1.6;
	data->screen.x_max = 1.6;
	data->screen.y_min = -1.477;
	data->screen.y_max = 1.5;
}

int	normal_julia_iter(t_complex *z, t_complex *c)
{
	int	i;
	double	temp;
	
	i = 0;
	temp = 0;
	while (abs_of_cmplx(*z) <= 2 && i < MAX_ITER)
	{
		temp = pow(z->r, 2) - pow(z->i, 2);
		z->i = 2 * z->r * z->i + c->i;
		z->r = temp + c->r;
		i++;
	}
	return (i);
}

void	normal_julia(t_data *data, t_complex *c, double x, double y)
{
	t_complex	z;
	int			iter;
	int			color;

	data->img.px_y = y;
	while (data->img.px_y < data->length)
	{
		data->img.px_x = x;
		while (data->img.px_x < data->width)
		{
			z = pxl_to_cmplx(data, data->img.px_x, data->img.px_y);
			iter = normal_julia_iter(&z, c);
			color = paint_my_wrld(iter, data);
			pixel_put(data, color);
			data->img.px_x++;
		}
		data->img.px_y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
