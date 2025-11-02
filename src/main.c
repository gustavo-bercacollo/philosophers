/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:21:28 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/02 20:00:18 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philos;

	if (!validate_args(argc, argv))
		return (1);
	if (!init_rules(&rules, argv))
    return (1);
	if (!init_forks(&rules))
	{
		pthread_mutex_destroy(&rules.state_mutex);
    pthread_mutex_destroy(&rules.write_mutex);
		return (1);
	}
	philos = malloc(rules.num_philos * sizeof(t_philo));
	if (!philos)
	{
		destroy_all_mutex(&rules);
		free(rules.forks);
		return (1);
	}
	init_philosophers(philos, &rules);
	start_simulation(philos, &rules);
	destroy_all_mutex(&rules);
	free_forks_and_philo(philos, &rules);
	return (0);
}
