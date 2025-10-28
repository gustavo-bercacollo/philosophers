/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:26:21 by gbercaco          #+#    #+#             */
/*   Updated: 2025/10/28 19:19:21 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void think(t_philo *philo, t_rules *rule)
{
  print_state(philo, rule, "is thinking");
  precise_sleep(200);
}

void sleep_filo(t_philo *philo, t_rules *rule, long long time_ms)
{
  print_state(philo, rule, "is sleeping");
  precise_sleep(time_ms);
}

// void take_forks()
// {
  
// }