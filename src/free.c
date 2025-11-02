/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:31:12 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/01 21:50:47 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy_all_mutex(t_rules *rules)
{
    int i;

    i = -1;
    while (++i < rules->num_philos)
        pthread_mutex_destroy(&rules->forks[i]);
}
