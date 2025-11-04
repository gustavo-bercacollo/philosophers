/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:52:38 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/04 16:52:58 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_death(t_philo *philo, t_rules *rule)
{
	long long	now;

	now = get_time() - rule->start_time;
	pthread_mutex_lock(&rule->write_mutex);
	printf("%lld %d died\n", now, philo->id);
	pthread_mutex_unlock(&rule->write_mutex);
}
