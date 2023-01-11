/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_philo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:35:20 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/10 21:29:13 by jeluiz4          ###   ########.fr       */
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
	int				alive;
	int				nb_phi;
	time_t			tm_start;
	int				tm_eat;
	int				tm_slp;
	int				tm_die;
	int				max_eat;
	pthread_t		waiter;
	pthread_mutex_t	end_table;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	printer;
	pthread_mutex_t	eat_time;
	pthread_mutex_t	check; //Vai que precisa de uma pausa pra checar algo né;
}				t_dinner;

typedef struct s_philo
{
	int				id;
	int				eated;
	time_t			last_meal;
	time_t			life_end;
	t_dinner		*blk;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;
}				t_philo;

int		ft_atoi(char *str, int i, long int out, int sign);
int		ft_space(char c);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*philo_routine(void *str);
time_t	ft_get_time(void);
int		ft_phi_init(t_dinner *blk);
void	ft_start_dinner(t_dinner *blk, pthread_t *phi, int i);
int		ft_build_door(t_dinner *blk, int i);
int		dinner_init(char **argv, t_dinner *blk, int argc);
void	sleep_route(t_philo *phi);
void	food_route(t_philo *phi);
void	think_route(t_philo *phi);
void	ft_print_status(t_philo *phi, char *str);

#endif
