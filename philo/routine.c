/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:07:13 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/10 13:06:46 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	ft_nap_time(t_philo *phi, time_t slp)
{
	time_t	wakeup;

	wakeup = ft_get_time() + slp;
	while (ft_get_time() < wakeup)
		usleep(350);
	printf("%d\n", phi->blk->tm_slp);
}

void	ft_print_status(t_philo *phi)
{
	time_t	live;

	live = ft_get_time() - phi->blk->tm_start;
	printf("%ld %d %s\n", live, phi->id, "Ação Aqui");
}

void	*philo_routine(void *phi)
{
	t_philo *din;

	din = (t_philo *)phi;
	ft_print_status(din);
	return (NULL);
}
