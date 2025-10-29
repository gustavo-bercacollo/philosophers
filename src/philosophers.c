/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:56:54 by gbercaco          #+#    #+#             */
/*   Updated: 2025/10/29 20:08:25 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *rotine(void *arg)
{
  t_philo *philo;
  t_rules *rule;

  philo = (t_philo *)arg;
  rule = philo->rule;
  
  if (philo->id % 2 == 0)
    usleep(1000);
  
  while (!rule->dead)
  {
    eat(philo, rule);
    if (rule->must_eat > 0 && philo->meals_eaten >= rule->must_eat)
      break;
    sleep_filo(philo, rule, rule->time_to_sleep);
    think(philo, rule);
  }
  return (NULL);
}

void monitor()
{
  
}
