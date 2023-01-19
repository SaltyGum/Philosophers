/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:19:04 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/19 15:28:43 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	ft_host_drop(t_philo *phi, char fork)
{
	if (RIGHT == fork)
	{
		pthread_mutex_unlock(&phi->blk->m_forks[0]);
	}
	if (LEFT == fork)
	{
		pthread_mutex_unlock(&phi->blk->m_forks[phi->id - 1]);
	}
}

void	ft_guests_drop(t_philo *phi, char fork)
{
	if (fork == RIGHT)
	{
		pthread_mutex_unlock(&phi->blk->m_forks[phi->id]);
	}
	if (fork == LEFT)
	{
		pthread_mutex_unlock(&phi->blk->m_forks[phi->id - 1]);
	}
}

void	ft_down_forks(t_philo *phi, char fork)
{
	if (phi->id == phi->blk->nb_phi)
		ft_host_drop(phi, fork);
	else
		ft_guests_drop(phi, fork);
}
