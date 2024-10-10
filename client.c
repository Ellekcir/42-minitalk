/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 03:53:57 by rgriffit          #+#    #+#             */
/*   Updated: 2024/10/04 10:36:19 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	send_character(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			kill(pid, SIGUSR2);
			ft_printf("SIGUSR2 HAS BEEN SENT - 1\n");
		}
		else
		{
			kill(pid, SIGUSR1);
			ft_printf("SIGUSR1 HAS BEEN SENT - 0\n");
		}
		usleep(200);
		bit--;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*message;
	int		i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		i = 0;
		while (message[i] != '\0')
		{
			send_character(pid, message[i]);
			ft_printf("\n");
			i++;
		}
	}
	else
	{
		ft_printf("ERROR - Insufficient arguments \n");
	}
	return (0);
}

// What is a server/client
// What is a PID
// What are the signal functions used
// What do they all do?
// How to run:
// make
// open two terminals
// in one window type in ./server
// then in the other type in ./client <PID> <message>
// use the PID from the server and type in your 
// chosen message using the syntax above
