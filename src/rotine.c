/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:26:21 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/04 13:46:52 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo, t_rules *rule)
{
	if (!is_dead(rule))
		print_state(philo, rule, "is thinking");
	precise_sleep(10);
}

void	sleep_filo(t_philo *philo, t_rules *rule, long long time_ms)
{
	if (!is_dead(rule))
		print_state(philo, rule, "is sleeping");
	precise_sleep(time_ms);
}

void	take_forks(t_philo *philo, t_rules *rule)
{
	pthread_mutex_lock(philo->left_fork);
	if (!is_dead(rule))
		print_state(philo, rule, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	if (!is_dead(rule))
		print_state(philo, rule, "has taken a fork");
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat(t_philo *philo, t_rules *rule)
{
	take_forks(philo, rule);
	if (!is_dead(rule))
		print_state(philo, rule, "is eating");
	pthread_mutex_lock(&rule->state_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&rule->state_mutex);
	precise_sleep(rule->time_to_eat);
	put_forks(philo);
	philo->meals_eaten++;
}
