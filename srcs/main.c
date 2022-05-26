/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:49:12 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/27 00:38:26 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char *argv[])
{
	int n = 23;

	if (argc < 2)
		show_error_msg();
	if (argv[1])
		n = find_set(argv[1]);
	get_started(argv[1]);
	return (0);
}