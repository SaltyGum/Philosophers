/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:44:31 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/19 17:45:55 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

int	phi_malloc(t_philo **phi, pthread_t **threads, t_dinner *blk)
{
	*phi = malloc(sizeof(t_philo) * (blk->nb_phi + 1));
	if (*phi == NULL)
		return (1);
	*threads = malloc(sizeof(pthread_t) * blk->nb_phi);
	if (*threads == NULL)
	{
		free(*phi);
		return (1);
	}
	ft_bzero(*threads, sizeof(pthread_t) * blk->nb_phi);
	return (0);
}

int	ft_phi_init(t_dinner *blk)
{
	t_philo		*phi;
	pthread_t	*threads;
	int			i;

	phi = NULL;
	threads = NULL;
	if (phi_malloc(&phi, &threads, blk))
		return (1);
	blk->tm_start = ft_get_time();
	i = -1;
	while (++i < blk->nb_phi)
	{
		phi[i].id = i + 1;
		phi[i].eated = 0;
		phi[i].last_meal = blk->tm_start;
		phi[i].blk = blk;
		if (pthread_mutex_init(&phi[i].plate, 0))
			return (free(phi), free(threads), 1);
		if (pthread_create(&threads[i], NULL, &philo_routine, &phi[i]))
			return (free(phi), free(threads), 1);
	}
	if (ft_waiter_start(phi, blk))
		return (free(threads), free(phi), 1);
	ft_start_dinner(blk, threads, 0);
	return (free(threads), free(phi), 0);
}
