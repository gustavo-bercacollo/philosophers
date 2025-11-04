/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:11:23 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/04 16:20:07 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Error, You need pass 5 or 6 args\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_positive_number(argv[i]))
		{
			printf("Error: argument %d is not a positive number\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

void	validate_if_have_one_philo(t_philo *philo, t_rules *rule)
{
	if (rule->num_philos == 1)
	{
		print_state(philo, rule, "has taken a fork");
		precise_sleep(rule->time_to_die);
		print_state(philo, rule, "died");
		rule->dead = 1;
		return ;
	}
	return ;
}

int	is_dead(t_rules *rule)
{
	int	dead;

	pthread_mutex_lock(&rule->state_mutex);
	dead = rule->dead;
	pthread_mutex_unlock(&rule->state_mutex);
	return (dead);
}
