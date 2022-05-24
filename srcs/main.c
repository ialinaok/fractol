/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:49:12 by apielasz          #+#    #+#             */
/*   Updated: 2022/05/24 10:58:19 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char *argv[])
{
	int	n = 0;
	if (argc < 3)
	{
		printf("Too few arguments!\n");
		while (n < argc)
		{
			printf("%s, %s\n", argv[0], argv[1]);
			n++;
		}
		return (0);
	}
}