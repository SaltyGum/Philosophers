/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:04 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/10 18:46:01 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

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
	free(blk.m_forks);
	return (0);
}
