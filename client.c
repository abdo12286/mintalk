/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:37:21 by hakader           #+#    #+#             */
/*   Updated: 2025/03/29 15:56:29 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_bin(unsigned char c, int bits[8])
{
	int		i;

	i = 8;
	while (i--)
	{
		bits[i] = c & 1;
		c >>= 1;
	}
}

void	send_bit(pid_t pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else if (bit == 0)
		kill(pid, SIGUSR2);
	usleep(150);
}

void	send_signals(pid_t pid, char *str)
{
	int			i;
	int			j;
	int			bits[8];

	i = 0;
	while (str[i])
	{
		char_bin(str[i], bits);
		j = 0;
		while (j < 8)
		{
			send_bit(pid, bits[j]);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		write(1, "Error: <Valid pid> <Message>\n", 30);
		exit(1);
	}
	pid = (pid_t)ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "Error: < pid invalid> \n", 24);
		exit(1);
	}
	send_signals(pid, av[2]);
	return (0);
}
