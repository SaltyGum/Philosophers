/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:17:02 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/10 21:28:27 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

void	sleep_route(t_philo *phi)
{
	ft_print_status(phi, "is sleeping");
}

void	food_route(t_philo *phi)
{
	
	ft_print_status(phi, "is eating");
}

void	think_route(t_philo *phi)
{
	ft_print_status(phi, "is thinking");
}
