/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:10:09 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/04 04:19:22 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# define BUFFER_SIZE 10000

typedef struct s_state {
	char	c;
	int		bit;
	char	msg[BUFFER_SIZE];
	int		len;
}		t_state;

void	send_signal(int pid, char c);
void	handle_signal(int sig, siginfo_t *info, void *context);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
int		check_pid(int pid);

#endif
