/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:45:06 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/21 17:45:39 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mintalk.h"

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

	printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
