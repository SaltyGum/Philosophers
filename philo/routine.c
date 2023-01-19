/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:07:13 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/19 16:33:02 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	ft_nap_time(t_philo *phi, time_t slp)
{
	time_t	wakeup;

	wakeup = ft_get_time() + slp;
	while (ft_get_time() < wakeup) // Checar morte durante o sono e matar;
	{
		pthread_mutex_lock(&phi->blk->end_table);
		if (phi->blk->a_live == 1)
		{
			pthread_mutex_unlock(&phi->blk->end_table);
			break ;
		}
		pthread_mutex_unlock(&phi->blk->end_table);
		usleep(5);
	}
}

void	ft_print_status(t_philo *phi, char *str)
{
	time_t	live;

	pthread_mutex_lock(&phi->blk->end_table);
	if (phi->blk->a_live == 0)
	{
		pthread_mutex_lock(&phi->blk->printer);
		live = ft_get_time() - phi->blk->tm_start;
		printf("%ld %d %s\n", live, phi->id, str);
		pthread_mutex_unlock(&phi->blk->printer);
	}
	pthread_mutex_unlock(&phi->blk->end_table);
}

void	*philo_routine(void *entry)
{
	t_philo	*phi;

	phi = (t_philo *)entry;
	if (phi->blk->nb_phi == 1)
		return (usleep(phi->blk->tm_die),
			printf("%d %d died\n", phi->blk->tm_die, phi->id), NULL);
	if (phi->id % 2 == 0)
		ft_nap_time(phi, 10);
	while (42)
	{
		pthread_mutex_lock(&phi->blk->end_table);
		if	(phi->blk->a_live == 1)
		{
			pthread_mutex_unlock(&phi->blk->end_table);
			break ;
		}
		pthread_mutex_unlock(&phi->blk->end_table);
		food_route(phi);
		sleep_route(phi);
		think_route(phi);
	}
	return (NULL);
}
