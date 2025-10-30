/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:56:54 by gbercaco          #+#    #+#             */
/*   Updated: 2025/10/30 19:19:03 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*rotine(void *arg)
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
	int		i;

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

// void	start_simulation(t_philo *philos, t_rules *rule)
// {
// 	int	i;

// 	i = 0;
// 	while (i < rule->num_philos)
// 	{
// 		pthread_create()
// 	}
	
// }