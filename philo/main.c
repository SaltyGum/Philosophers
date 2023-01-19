/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:04 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/19 17:46:26 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	ft_start_dinner(t_dinner *blk, pthread_t *phi, int i)
{
	while (i < blk->nb_phi)
	{
		pthread_join(phi[i], NULL);
		i++;
	}
	if (blk->nb_phi > 1)
	{
		pthread_join(blk->waiter, NULL);
	}
}

void	mutex_exit(t_dinner *blk, int i)
{
	while (i < blk->nb_phi)
	{
		pthread_mutex_destroy(&blk->m_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&blk->end_table);
	pthread_mutex_destroy(&blk->printer);
}

int	main(int argc, char *argv[])
{
	t_dinner	blk;

	if (argc < 5 || argc > 6)
		return (printf("Too Few or Too Many Args Fella\n"), 1);
	if (!dinner_init(argv, &blk, argc))
		return (printf("Wrong Args Fella\n"), 1);
	if (ft_phi_init(&blk))
	{
		free(blk.m_forks);
		return (printf("Thread Create Failed\n"), 2);
	}
	mutex_exit(&blk, 0);
	free(blk.m_forks);
	return (0);
}
