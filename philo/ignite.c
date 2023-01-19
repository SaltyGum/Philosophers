/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:37 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/19 17:46:31 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

int	dinner_init(char **argv, t_dinner *blk, int argc)
{
	blk->i = 0;
	blk->nb_phi = ft_atoi(argv[1], 0, 0, 1);
	blk->tm_die = ft_atoi(argv[2], 0, 0, 1);
	blk->tm_eat = ft_atoi(argv[3], 0, 0, 1);
	blk->tm_slp = ft_atoi(argv[4], 0, 0, 1);
	blk->a_live = 0;
	blk->sf_phi = 0;
	if (argc == 6)
	{
		blk->max_eat = ft_atoi(argv[5], 0, 0, 1);
		if (blk->max_eat <= 0)
			return (0);
	}
	if ((blk->nb_phi) <= 0 || (blk->tm_die <= 0)
		|| (blk->tm_eat <= 0) || (blk->tm_slp <= 0))
		return (0);
	if (ft_build_door(blk, 0))
	{
		return (0);
	}
	return (1);
}

int	ft_init_mutex(t_dinner *blk)
{
	blk->m_forks = malloc(sizeof(pthread_mutex_t) * blk->nb_phi);
	if (blk->m_forks == NULL)
		return (1);
	return (0);
}

int	ft_build_door(t_dinner *blk, int i)
{
	if (ft_init_mutex(blk))
		return (1);
	while (i < blk->nb_phi)
	{
		if (pthread_mutex_init(&blk->m_forks[i], 0))
		{
			printf("Crash on mutex init\n");
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&blk->printer, 0))
		return (1);
	if (pthread_mutex_init(&blk->end_table, 0))
		return (1);
	return (0);
}
