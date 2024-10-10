/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:55:52 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 00:44:23 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function memchr searches n bytes of the memory area pointed to
	by s. The memchr() function locates the first 
	occurrence of c (converted to an unsigned char) in string s.

	RETURN VALUE:
	A pointer to the matching byte, 
	or NULL if no such byte exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*strinmem;
	unsigned char		chrsrch;
	size_t				i;

	chrsrch = (unsigned char)c;
	strinmem = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (strinmem[i] == chrsrch)
		{
			return ((void *)&strinmem[i]);
		}
		i++;
	}
	return (NULL);
}
