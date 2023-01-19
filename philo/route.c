/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:17:02 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/19 16:15:22 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	sleep_route(t_philo *phi)
{
	ft_print_status(phi, "is sleeping");
	ft_nap_time(phi, phi->blk->tm_slp);
}

void	think_route(t_philo *phi)
{
	ft_print_status(phi, "is thinking");
}

void	ft_eating(t_philo *phi)
{
	pthread_mutex_lock(&phi->plate);
	phi->eated++;
	if (phi->eated == phi->blk->max_eat)
		phi->blk->sf_phi++;
	phi->last_meal = ft_get_time();
	pthread_mutex_unlock(&phi->plate);
	ft_nap_time(phi, phi->blk->tm_eat);
}

void	food_route(t_philo *phi)
{
	ft_up_forks(phi, RIGHT);
	ft_up_forks(phi, LEFT);
	ft_print_status(phi, "is eating");
	ft_eating(phi);	
	ft_down_forks(phi, RIGHT);
	ft_down_forks(phi, LEFT);
}
