/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:04 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/08 21:27:03 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	*route(void *str)
{
	int	i;

	i = 0;
	while (i < 10000000)
	{
		i++;
	}
	printf("Hello from %s\n", (char *)str);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		((char *)s)[n - 1] = '\0';
		n--;
	}
}

// ARGV -- NB_PHILO, TIME_DIE, TIME_EAT, TIME_SLEEP, "MAX_EAT"
int	blk_init(char **argv, t_dinner *blk, int argc)
{
	blk->i = 0;
	blk->nb_phi = ft_atoi(argv[1], 0, 0, 1);
	blk->tm_die = ft_atoi(argv[2], 0, 0, 1);
	blk->tm_eat = ft_atoi(argv[3], 0, 0, 1);
	blk->tm_slp = ft_atoi(argv[4], 0, 0, 1);
	if (argc == 6)
	{
		blk->max_eat = ft_atoi(argv[5], 0, 0, 1);
		if (blk->max_eat <= 0)
			return (0);
	}
	if ((blk->nb_phi) <= 0 || (blk->tm_die <= 0)
		|| (blk->tm_eat <= 0) || (blk->tm_slp <= 0))
		return (0);
	blk->phi = malloc(sizeof(blk->phi) * blk->nb_phi);
	ft_bzero(blk->phi, sizeof(blk->phi) * blk->nb_phi);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_dinner	blk;

	if (argc < 5 || argc > 6)
		return (printf("Wrong Args Fella\n"), 1);
	if (!blk_init(argv, &blk, argc))
		return (printf("Wrong Args Fella\n"), 1);
	while (blk.i < blk.nb_phi)
	{
		printf("BLK I %d \n", blk.i);
		pthread_create(blk.phi + blk.i, NULL, &route, "PARADISE");
		blk.i++;
	}
	blk.i = 0;
	while (blk.i < blk.nb_phi)
	{
		printf("closing %d\n", blk.i);
		pthread_join(blk.phi[blk.i], NULL);
		blk.i++;
	}
	blk.i = argc;
	argc = blk.i;
	argv[0][0] = 'j';
	blk.i = 0;
	free (blk.phi);
	return (0);
}
