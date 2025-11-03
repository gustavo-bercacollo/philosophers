/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:11:23 by gbercaco          #+#    #+#             */
/*   Updated: 2025/11/02 23:11:36 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int validate_args(int argc, char **argv)
{
	int i;
	
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