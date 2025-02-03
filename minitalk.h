#ifndef MINITALK_H
#define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void    send_signal(int pid, char c);
void    handle_signal(int sig, siginfo_t *info, void *context);
int     ft_atoi(const char *str);
void    ft_putnbr(int n);
void    ft_putstr(char *str);

#endif

