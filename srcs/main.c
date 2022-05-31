/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:49:12 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/31 20:05:30 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char *argv[])
{
	int	set;
	int	color;

	set = -1;
	color = -1;
	if (argc < 2)
		show_error_msg();
	if (argv[1])
		set = find_set(argv[1]);
	if (argv[2])
	{
		color = find_color(argv[2]);
	}
	get_started(set, color);
	return (0);
}