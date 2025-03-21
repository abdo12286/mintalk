/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:45:06 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/21 22:15:52 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mintalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		 ft_putnbr(n / 10);
		  ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		 ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n <= 9)
	{
		 ft_putchar(n + '0');
	}
	return (i);
}


void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	received_char;
	static int				bit_count;
	static int				last_pid = -1;

	(void)context;
	if (last_pid != info->si_pid)
	{
		received_char = 0;
		bit_count = 0;
		last_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		received_char <<= 1;
	else if (sig == SIGUSR2)
		received_char = (received_char << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &received_char, 1);
		received_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	write(1, "Server PID:",11);
	ft_putnbr(getpid());
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
