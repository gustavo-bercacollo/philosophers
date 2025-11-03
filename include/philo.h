/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:14:28 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/03 18:59:11 by gbercaco         ###   ########.fr       */
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
	int				must_eat;
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

// init
int					init_rules(t_rules *rules, char **argv);
int					init_forks(t_rules *rules);
int					init_philosophers(t_philo *philo, t_rules *rules);

// rotine
void				think(t_philo *philo, t_rules *rule);
void				eat(t_philo *philo, t_rules *rule);
void				sleep_filo(t_philo *philo, t_rules *rule,
						long long time_ms);
void				take_forks(t_philo *philo, t_rules *rule);

// philosophres
void				*routine(void *arg);
void				*monitor(void *arg);
void				start_simulation(t_philo *philos, t_rules *rule);

// validate
int					validate_args(int argc, char **argv);
void				validate_if_have_one_philo(t_philo *philo, t_rules *rule);

// free
void				destroy_all_mutex(t_rules *rules);
void				free_forks_and_philo(t_philo *philos, t_rules *rule);

// utils
int					ft_atoi(const char *nptr);
int					is_positive_number(char *str);
long long			get_time(void);
void				print_state(t_philo *philo, t_rules *rule, char *action);
void				precise_sleep(long long time_ms);

#endif