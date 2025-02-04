/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:16:32 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/04 04:19:44 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_ack_received = 0;

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

int	is_server_alive(int pid)
{
	if (kill(pid, 0) == -1 && errno == ESRCH)
		return (0);
	return (1);
}

void	send_signal_bit(int pid, char c, int i)
{
	int	result;

	if (!is_server_alive(pid))
	{
		write(2, "Erreur : serveur Inactif.\n", 26);
		exit(1);
	}
	if ((c >> i) & 1)
		result = kill(pid, SIGUSR1);
	else
		result = kill(pid, SIGUSR2);
	if (result == -1)
	{
		write(2, "Error: Failed to send signal\n", 29);
		exit(1);
	}
}

void	send_signal(int pid, char c)
{
	int	i;
	int	timeout;

	g_ack_received = 0;
	i = 8;
	timeout = 0;
	while (i--)
	{
		send_signal_bit(pid, c, i);
		while (!g_ack_received)
		{
			usleep(100);
			timeout += 100;
			if (timeout > 2000000 || !is_server_alive(pid))
			{
				write(2, "Erreur : No response serveur.\n", 30);
				exit(1);
			}
		}
		g_ack_received = 0;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (write(1, "Usage: ./client <PID> <message>\n", 33));
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || !check_pid(pid))
	{
		write(1, "Invalid PID\n", 12);
		return (1);
	}
	signal(SIGUSR1, signal_handler);
	i = -1;
	while (argv[2][++i])
		send_signal(pid, argv[2][i]);
	send_signal(pid, '\0');
	return (0);
}
