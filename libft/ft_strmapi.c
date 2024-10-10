/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:06:05 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/05 03:45:22 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DECRIPTION:
s: The string on which to iterate.
f: the function to apply to each character.
Applies function 'f' to each character off the 's' string, and passing it's 
index as first argument to create a new string with malloc resulting from 
successive applications of 'f'. 
RETURN:
A new string resulting of the successive applications of 'f'; NULL if the memory
allocations failed.
*/

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
