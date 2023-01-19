/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:33:30 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/19 17:36:57 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

int	philo_alive(t_philo *phi)
{
	long	live;

	live = ft_get_time();
	if (phi->last_meal != 0 && (live - phi->last_meal) >= phi->blk->tm_die)
	{
		pthread_mutex_lock(&phi->blk->end_table);
		phi->blk->a_live = 1;
		pthread_mutex_unlock(&phi->blk->end_table);
		usleep(20);
		pthread_mutex_lock(&phi->blk->printer);
		live = ft_get_time() - phi->blk->tm_start;
		printf("%ld %d %s \n", live, phi->id, "died");
		pthread_mutex_unlock(&phi->blk->printer);
		return (0);
	}
	return (1);
}

int	philo_satisfied(t_philo *phi)
{
	if (phi->blk->sf_phi == phi->blk->nb_phi)
	{
		pthread_mutex_lock(&phi->blk->end_table);
		phi->blk->a_live = 1;
		pthread_mutex_unlock(&phi->blk->end_table);
		return (1);
	}
	return (0);
}

void	*waiter_routine(void *entry)
{
	t_philo *phi;
	int		i;

	phi = (t_philo *)entry;
	i = 0;
	while (42)
	{
		pthread_mutex_lock(&phi[i].plate);
		if (!philo_alive(&phi[i]))
		{
			pthread_mutex_unlock(&phi[i].plate);
			break ;
		}
		if (philo_satisfied(&phi[i]))
		{
			pthread_mutex_unlock(&phi[i].plate);
			break ;
		}
		pthread_mutex_unlock(&phi[i].plate);
		i++;
		if (i == phi[0].blk->nb_phi)
			i = 0;
	}
	return (NULL);
}

int	ft_waiter_start(t_philo *phi, t_dinner *blk)
{
	if (blk->nb_phi > 1)
	{
		if (pthread_create(&blk->waiter, NULL, &waiter_routine, phi))
			return (1);
	}
	return (0);
}
