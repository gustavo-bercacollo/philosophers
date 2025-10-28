/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:21:28 by gbercaco          #+#    #+#             */
/*   Updated: 2025/10/28 17:50:51 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(void)
{
  t_rules rule;
  t_philo philo;

  rule.start_time = get_time();
  philo.id = 1;

  for (int i = 0; i < 5; i++)
      think(&philo, &rule);

  return 0;
}