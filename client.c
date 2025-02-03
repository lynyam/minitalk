#include "minitalk.h"

int	ack_received = 0;

void signal_handler(int sig)
{
    if (sig == SIGUSR1)
        ack_received = 1;  // Marquer que la confirmation a été reçue
}

void send_signal(int pid, char c)
{
    int i;
    ack_received = 0;

    i = 8;
    while (i--)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
	while (!ack_received) 
            pause();
	ack_received = 0;
        usleep(150);
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    if (argc != 3)
        return (write(1, "Usage: ./client <PID> <message>\n", 33));
    pid = ft_atoi(argv[1]);
    signal(SIGUSR1, signal_handler);
    i = -1;
    while (argv[2][++i])
        send_signal(pid, argv[2][i]);
    send_signal(pid, '\0');
    return (0);
}

