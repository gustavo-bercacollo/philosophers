/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:21:28 by gbercaco          #+#    #+#             */
/*   Updated: 2025/10/30 16:14:13 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(void)
{
	t_rules	rule;
	t_philo	philo;

	rule.start_time = get_time();
	philo.id = 1;
	rule.dead = 0;

	for (int i = 0; i < 5; i++)
		think(&philo, &rule);

	return (0);
}
