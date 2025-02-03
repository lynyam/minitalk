#include "minitalk.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static char c = 0;
    static int bit = 0;

    (void)context;
    if (sig == SIGUSR1)
        c |= (1 << (7 - bit));
    bit++;
    if (bit == 8)
    {
        write(1, &c, 1);
        bit = 0;
        c = 0;
    }
   kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;

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
