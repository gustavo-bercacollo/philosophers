/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:56:54 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/01 16:15:10 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_rules	*rule;

	philo = (t_philo *)arg;
	rule = philo->rule;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!rule->dead)
	{
		eat(philo, rule);
		if (rule->must_eat > 0 && philo->meals_eaten >= rule->must_eat)
			break ;
		sleep_filo(philo, rule, rule->time_to_sleep);
		think(philo, rule);
	}
	return (NULL);
}

static void	check_is_dead(t_philo *philos, t_rules *rule)
{
	int	i;

	while (!rule->dead)
	{
		i = 0;
		while (i < rule->num_philos && !rule->dead)
		{
			if ((get_time() - philos[i].last_meal) > rule->time_to_die)
			{
				pthread_mutex_lock(&rule->state_mutex);
				if (!rule->dead)
				{
					rule->dead = 1;
					pthread_mutex_unlock(&rule->state_mutex);
					print_state(&philos[i], rule, "died");
				}
				else
					pthread_mutex_unlock(&rule->state_mutex);
			}
			usleep(1000);
			i++;
		}
	}
}

void	*monitor(void *arg)
{
	t_philo	*philos;
	t_rules	*rule;

	philos = (t_philo *)arg;
	rule = philos->rule;
	check_is_dead(philos, rule);
	return (NULL);
}

void	start_simulation(t_philo *philos, t_rules *rule)
{
	int	i;

	i = -1;
	while (++i < rule->num_philos)
	{
		if (pthread_create(&philos[i].thread_id, NULL, routine,
				&philos[i]) != 0)
		{
			printf("Erro to create thread %d\n", i);
			return ;
		}
	}
	if (pthread_create(&rule->thread_monitor_id, NULL, monitor, philos))
	{
		printf("Erro to create the monitor thread %d\n", i);
		return ;
	}
	i = -1;
	while (++i < rule->num_philos)
	{
		if (pthread_join(philos[i].thread_id, NULL))
			printf("Erro to wait thread %d\n", i);
	}
	if (pthread_join(rule->thread_monitor_id, NULL))
		printf("Erro to wait the monitor thread\n");
}


