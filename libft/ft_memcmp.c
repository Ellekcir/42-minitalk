/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:54:27 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 00:42:16 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION: 	
	The memcmp() function compares byte string s1 against byte string s2.
	Both strings are assumed to be n bytes long.

	RETURN: 	
	The memcmp() function returns zero if the two strings are identical, 
	otherwise returns the difference between the first two differing bytes 
	(treated as unsigned char values, so that `\200' is greater than `\0',
	for example).
	Zero-length strings are always identical.  
	This behavior is not required by C and portable c
	ode should only depend on the sign of the returned value.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
