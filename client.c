/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:45:12 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/21 17:46:44 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mintalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	put_err(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	write(2, str, ft_strlen(str));
	exit(1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		put_err("please just <pid>");
	return (result * sign);
}

void	send_bin(unsigned char av, pid_t num)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (((av >> j) & 1) == 0)
			kill(num, SIGUSR1);
		else
			kill(num, SIGUSR2);
		usleep(400);
		j--;
	}
}

int	main(int ac, char **av)
{
	pid_t	num;
	int		i;

	i = 0;
	if (ac != 3)
		put_err("you just need <pid> <Message>\n");
	num = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_bin(av[2][i], num);
		i++;
	}
	send_bin('\0', num);
	return (0);
}
