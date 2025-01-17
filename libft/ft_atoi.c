/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:22:02 by rgriffit          #+#    #+#             */
/*   Updated: 2024/10/04 11:48:44 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
     The atoi() function converts the initial por-
     tion of the string pointed to by str to int
     representation.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	negative;
	int	result;
	int	found;

	result = 0;
	found = 1;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			result = (result * 10) + (*str - '0');
		else
			found = 0;
		str++;
	}
	return (result * negative);
}
