/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:14:28 by gbercaco          #+#    #+#             */
/*   Updated: 2025/10/30 00:06:28 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_rules {
	int		num_philos;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int		must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	state_mutex;
	long long	start_time;
	int	dead;
}	t_rules;


typedef struct s_philo
{
	int	id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long	last_meal;
	int	meals_eaten;
	t_rules	*rule;
}	t_philo;


//utils
void print_state(t_philo *philo, t_rules *rule, char *action);
void think(t_philo *philo, t_rules *rule);
long long get_time(void);
void precise_sleep(long long time_ms);
void sleep_filo(t_philo *philo, t_rules *rule, long long time_ms);
void take_forks(t_philo *philo, t_rules *rule);
void eat(t_philo *philo, t_rules *rule);
void *rotine(void *arg);

#endif