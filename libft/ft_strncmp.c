/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:25:30 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 16:42:31 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
	 The strcmp() and strncmp() func-
     tions lexicographically compare
     the null-terminated strings s1
     and s2.

     The strncmp() function compares
     not more than n characters.
     Because strncmp() is designed
     for comparing strings rather
     than binary data, characters
     that appear after a `\0' charac-
     ter are not compared.
RETURN:
     The strcmp() and strncmp() func-
     tions return an integer greater
     than, equal to, or less than 0,
     according as the string s1 is
     greater than, equal to, or less
     than the string s2.  The compar-
     ison is done using unsigned
     characters, so that `\200' is
     greater than `\0'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
