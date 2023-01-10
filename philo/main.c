/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:04 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/10 13:01:24 by jeluiz4          ###   ########.fr       */
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
	blk->m_forks = malloc(sizeof(pthread_mutex_t *) * blk->nb_phi);
	return (1);
}

void	ft_start_dinner(t_dinner *blk, pthread_t *phi, int i)
{
	while (i < blk->nb_phi)
	{
		pthread_join(phi[i], NULL);
		printf("closing %d\n", i);
		i++;
		usleep(100);
	}
}

int	ft_phi_init(t_dinner *blk)
{
	t_philo		*phi;
	pthread_t	*threads;
	int			i;

	i = -1;
	phi = malloc(sizeof(t_philo) * blk->nb_phi);
	threads = malloc(sizeof(pthread_t) * blk->nb_phi);
	ft_bzero(threads, sizeof(pthread_t) * blk->nb_phi);
	blk->tm_start = ft_get_time();
	while (++i < blk->nb_phi)
	{
		phi[i].id = i + 1;
		phi[i].eated = 0;
		phi[i].blk = blk;
		if (pthread_create(&threads[i], NULL, &philo_routine, &phi[i]))
		{
			puts("entrei\n");
			free(phi);
			free(threads);
			return (1);
		}
	}
	ft_start_dinner(blk, threads, 0);
	free(threads);
	free(phi);
	return (0);
}

/*int	ft_place_table(t_dinner *blk, t_philo *phi)
{
	blk->tm_start = ft_get_time();
	while (blk->i < blk->nb_phi)
	{
		printf("BLK I %d \n", blk->i);
			if (pthread_create((phi[blk->i])->t_phi, NULL, philo_routine, blk))
			break ;
		blk->i++;
	}
	if (blk->i == blk->nb_phi)
		return (0);
	else
		return (blk->i);
}*/


int	main(int argc, char *argv[])
{
	t_dinner	blk;

	if (argc < 5 || argc > 6)
		return (printf("Too Few or Too Many Args Fella\n"), 1);
	if (!blk_init(argv, &blk, argc))
		return (printf("Wrong Args Fella\n"), 1);
	//ft_phi_init(&blk, &phi);
	if (ft_phi_init(&blk))
	{
		//Dar free na matrix de philos
		return (printf("Thread Create Failed\n"), 2);
	}
	return (0);
}
