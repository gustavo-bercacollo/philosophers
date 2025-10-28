/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:41:39 by gbercaco          #+#    #+#             */
/*   Updated: 2025/10/28 17:51:46 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_time(void)
{
  struct timeval current_time;
  gettimeofday(&current_time, NULL);
  return (current_time.tv_sec * 1000LL) + (current_time.tv_usec / 1000);
}


void print_state(t_philo *philo, t_rules *rule, char *action)
{
  long long now = get_time() - rule->start_time;
  printf("%lld %d %s\n", now, philo->id, action);
  // talvez colocar um fflush
}