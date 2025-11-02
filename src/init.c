/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:33:46 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/02 19:36:57 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_rules(t_rules *rules, char **argv)
{
	rules->start_time = get_time();
	rules->dead = 0;
	rules->forks = NULL;
	rules->num_philos = ft_atoi(argv[1]); 
	rules->time_to_die = ft_atoi(argv[2]); 
	rules->time_to_eat = ft_atoi(argv[3]); 
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules->must_eat = ft_atoi(argv[5]);
	else
		rules->must_eat = -1;
	if (pthread_mutex_init(&rules->state_mutex, NULL) != 0)
	{
		printf("Error: failed to init state_mutex\n");
		return (0);
	}
	if (pthread_mutex_init(&rules->write_mutex, NULL) != 0)
	{
		printf("Error: failed to init write_mutex\n");
		pthread_mutex_destroy(&rules->state_mutex);
		return (0);
	}
		return (1);
	}

int	init_forks(t_rules *rules)
{
	int	i;

	rules->forks = malloc(rules->num_philos * sizeof(pthread_mutex_t));
	if (!rules->forks)
		return (0);
	i = -1;
	while (++i < rules->num_philos)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&rules->forks[i]);
			free(rules->forks);
			return (0);
		}
	}
	return (1);
}

int	init_philosophers(t_philo *philo, t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->num_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = get_time();
		philo[i].left_fork = &rules->forks[i];
		philo[i].right_fork = &rules->forks[(i + 1) % rules->num_philos];
		philo[i].rule = rules;
	}
	return (0);
}

