/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:14:28 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/01 22:04:03 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_rules
{
	int				num_philos;
	int number_of_times_each_philosopher_must_eat;
	int				dead;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	state_mutex;
	pthread_t		thread_monitor_id;
}					t_rules;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_rules			*rule;
}					t_philo;

// utils
void				print_state(t_philo *philo, t_rules *rule, char *action);
void				think(t_philo *philo, t_rules *rule);
long long			get_time(void);
void				precise_sleep(long long time_ms);
void				sleep_filo(t_philo *philo, t_rules *rule,
						long long time_ms);
void				take_forks(t_philo *philo, t_rules *rule);
void				eat(t_philo *philo, t_rules *rule);
void				*routine(void *arg);
void				*monitor(void *arg);
void	start_simulation(t_philo *philos, t_rules *rule);
int validate_args(int argc, char **argv);
int	ft_atoi(const char *nptr);
void init_rules(t_rules *rules, char **argv);
int	init_philosophers(t_philo *philo, t_rules *rules);
void destroy_all_mutex(t_rules *rules);
int	init_forks(t_rules *rules);

#endif