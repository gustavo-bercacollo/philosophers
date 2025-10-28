/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:14:28 by gbercaco          #+#    #+#             */
/*   Updated: 2025/10/27 23:41:29 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>


typedef struct s_rules {
	int		num_philos;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int		must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	long long	start_time;
}	t_rules;


typedef struct s_philo
{
	int	id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long	last_meal;
	int	meals_eaten;
	t_rules	*rules;
}	t_philo;

#endif