/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 02:44:22 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/04 04:20:07 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static t_state	state = {0, 0, {0}, 0};

	(void)context;
	if (sig == SIGUSR1)
		state.c |= (1 << (7 - state.bit));
	state.bit++;
	if (state.bit == 8)
	{
		if (state.c == '\0' || state.len >= BUFFER_SIZE - 1)
		{
			state.msg[state.len] = '\0';
			write(1, state.msg, state.len);
			state.len = 0;
		}
		if (state.c != '\0')
			state.msg[state.len++] = state.c;
		state.bit = 0;
		state.c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
