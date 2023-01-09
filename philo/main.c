/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:04 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/09 00:42:16 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

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

int	ft_place_table(t_dinner *blk)
{
	while (blk->i < blk->nb_phi)
	{
		printf("BLK I %d \n", blk->i);
			if (pthread_create(blk->phi + blk->i, NULL, philo_routine, "PARADISE"))
			break ;
		blk->i++;
	}
	if (blk->i == blk->nb_phi)
		return (0);
	else
		return (blk->i);
}

void	ft_start_dinner(t_dinner *blk, int i)
{
	while (i < blk->nb_phi)
	{
		printf("closing %d\n", i);
		pthread_join(blk->phi[i], NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_dinner	blk;

	if (argc < 5 || argc > 6)
		return (printf("Too Few or Too Many Args Fella\n"), 1);
	if (!blk_init(argv, &blk, argc))
		return (printf("Wrong Args Fella\n"), 1);
	if (ft_place_table(&blk))
	{
		free (blk.phi);
		return (printf("Thread Create Failed\n"), 2);
	}
	ft_start_dinner(&blk, 0);
	free (blk.phi);
	return (0);
}
