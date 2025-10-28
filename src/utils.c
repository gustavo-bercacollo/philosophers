/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:41:39 by gbercaco          #+#    #+#             */
/*   Updated: 2025/10/28 15:04:41 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_state(t_philo *philo, t_rules *rule, char *action)
{
  printf("%lld %d is %s\n", rule->start_time, philo->id, action);
  // talvez colocar um fflush
}
