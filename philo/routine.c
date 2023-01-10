/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:07:13 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/10 18:37:16 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	ft_nap_time(t_philo *phi, time_t slp)
{
	time_t	wakeup;

	wakeup = ft_get_time() + slp;
	while (ft_get_time() < wakeup) // Checar morte durante o sono e matar;
		usleep(350);
	printf("%d\n", phi->blk->tm_slp);
}

void	ft_print_status(t_philo *phi, char *str)// Usar para o status check do usuario str == ação atual;
{
	time_t	live;

	pthread_mutex_lock(&phi->blk->printer);//Muda o nome batata;
	live = ft_get_time() - phi->blk->tm_start;
	printf("%ld %d %s\n", live, phi->id, str);
	phi->eated++;
	pthread_mutex_unlock(&phi->blk->printer);//Muda o nome batata;
}

void	*philo_routine(void *phi)
{
	t_philo *din;

	din = (t_philo *)phi;
	while (42)
	{
		ft_print_status(din, "Testing Babe");
		if (((din->blk->max_eat - 1) == din->eated)
			&& din->blk->max_eat > 0)
			break ;
	}
	return (NULL);
}
