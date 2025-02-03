#include "minitalk.h"

int ft_atoi(const char *str)
{
    int res = 0;
    while (*str >= '0' && *str <= '9')
        res = res * 10 + (*str++ - '0');
    return (res);
}

void ft_putnbr(int n)
{
    char c;
    if (n > 9)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

