/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:31:12 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/02 19:59:03 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy_all_mutex(t_rules *rules)
{
  int i;

  i = -1;
  while (++i < rules->num_philos)
      pthread_mutex_destroy(&rules->forks[i]);
  pthread_mutex_destroy(&rules->state_mutex);
	pthread_mutex_destroy(&rules->write_mutex);
}
void free_forks_and_philo(t_philo *philos, t_rules *rule)
{
  free(rule->forks);
  free(philos);
}