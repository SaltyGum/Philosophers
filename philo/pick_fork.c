/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:18:51 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/19 15:49:00 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	ft_host_pick(t_philo *phi, char fork)
{
	if (RIGHT == fork)
	{
		pthread_mutex_lock(&phi->blk->m_forks[0]);
		ft_print_status(phi, "has taken a fork");
	}
	if (LEFT == fork)
	{
		pthread_mutex_lock(&phi->blk->m_forks[phi->id - 1]);
		ft_print_status(phi, "has taken a fork");
	}
}

void	ft_guests_pick(t_philo *phi, char fork)
{
	if (RIGHT == fork)
	{
		pthread_mutex_lock(&phi->blk->m_forks[phi->id]);
		ft_print_status(phi, "has taken a fork");
	}
	if (LEFT == fork)
	{
		pthread_mutex_lock(&phi->blk->m_forks[phi->id - 1]);
		ft_print_status(phi, "has taken a fork");
	}
}

void	ft_up_forks(t_philo *phi, char fork)
{
	if (phi->id == phi->blk->nb_phi)
		ft_host_pick(phi, fork);
	else
		ft_guests_pick(phi, fork);
}
