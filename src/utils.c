/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:41:39 by gbercaco          #+#    #+#             */
/*   Updated: 2025/10/29 23:09:50 by gbercaco         ###   ########.fr       */
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
  pthread_mutex_lock(&rule->write_mutex);
  printf("%lld %d %s\n", now, philo->id, action);
  pthread_mutex_unlock(&rule->write_mutex);
}

void precise_sleep(long long time_ms)
{
    long long start = get_time();
    while (get_time() - start < time_ms)
        usleep(100);
}
