/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:33:46 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/01 19:08:41 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_rules *rules)
{
	int	i;

	rules->forks = malloc(rules->num_philos * sizeof(pthread_mutex_t));
	if (!rules->forks)
		return (1);
	i = -1;
	while (++i < rules->num_philos)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&rules->forks[i]);
			free(rules->forks);
			return (1);
		}
	}
	return (0);
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

