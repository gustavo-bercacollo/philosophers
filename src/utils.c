/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:41:39 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/01 18:51:56 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_positive_number(char *str)
{
    int i = 0;
    if (!str || str[0] == '\0')
        return 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000LL) + (current_time.tv_usec / 1000);
}

void	print_state(t_philo *philo, t_rules *rule, char *action)
{
	long long	now;

	now = get_time() - rule->start_time;
	pthread_mutex_lock(&rule->write_mutex);
	printf("%lld %d %s\n", now, philo->id, action);
	pthread_mutex_unlock(&rule->write_mutex);
}

void	precise_sleep(long long time_ms)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time_ms)
		usleep(100);
}
int validate_args(int argc, char **argv)
{
	int i;
	
	if (argc != 6)
	{
		printf("Error, You need pass exactly 6 args\n");
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