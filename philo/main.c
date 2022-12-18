/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:04 by jeluiz4           #+#    #+#             */
/*   Updated: 2022/12/18 15:48:13 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

int	main(int argc, char *argv[])
{
	int	i;

	i = argc;
	i = 0;
	argv[0][0] = 'j';
	while (i < 10)
	{
		printf("EAT\n");
		usleep(100000);
		printf("SLEEP\n");
		usleep(100000);
		printf("THINK AND REPEAT\n");
		usleep(100000);
		i++;
	}
	return (0);
}
