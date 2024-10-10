/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 03:54:40 by rgriffit          #+#    #+#             */
/*   Updated: 2024/09/30 03:54:48 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	signal_handler(int sig)
{
	static int	bit = 7;
	static char	char_byte = 0;

	if (sig == SIGUSR1)
		char_byte = char_byte << 1;
	else if (sig == SIGUSR2)
		char_byte = (char_byte << 1) | 1;
	if (bit == 0)
	{
		ft_printf("%c", char_byte);
		char_byte = 0;
		bit = 7;
	}
	else
	{
		bit--;
	}
}

int	main(void)
{
	ft_printf("GREAT! You have activated the Server\n");
	ft_printf("Please use the PID for the Client to send a message\n");
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
