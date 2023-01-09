/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_philo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:35:20 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/08 21:27:28 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PHILO_H
# define LIB_PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int			id;
	int			eated;
	pthread_t	*phi;
}				t_philo;

typedef struct s_dinner
{
	int			i;
	int			nb_phi;
	int			tm_eat;
	int			tm_slp;
	int			tm_die;
	int			max_eat;
	pthread_t	*phi;
}				t_dinner;

int	ft_atoi(char *str, int i, long int out, int sign);
int	ft_space(char c);
int	ft_isdigit(int c);
#endif
