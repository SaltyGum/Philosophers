/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_philo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:35:20 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/09 18:52:24 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PHILO_H
# define LIB_PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_dinner
{
	int				i;
	int				nb_phi;
	time_t			tm_start;
	int				tm_eat;
	int				tm_slp;
	int				tm_die;
	int				max_eat;
	pthread_mutex_t	*m_forks;
	pthread_t		*murderer;
}				t_dinner;

typedef struct s_philo
{
	int			id;
	int			eated;
	t_dinner	*blk;
}				t_philo;

int		ft_atoi(char *str, int i, long int out, int sign);
int		ft_space(char c);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*philo_routine(void *str);
time_t	ft_get_time(void);
#endif
