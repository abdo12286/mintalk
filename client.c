#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;
	sign = 1;
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
	return(result * sign);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return(0);
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
	write (2, str, ft_strlen(str));
	exit (1);
}
void	send_bin(unsigned char av, pid_t num)
{
	int	j;

	j = 8;
	while(j >= 0)
	{
		if(((av >> j) & 1) == 0)
			kill(num, SIGUSR1);
		else
			kill(num, SIGUSR2);
		j--;
	}
}

int	main(int ac, char **av)
{
	pid_t	num;

	int	i;

	i = 0;
	if (ac != 3)
		put_err("you just need <pid> <Message>\n");
	num = ft_atoi(av[1]);
	while(av[2][i])
	{
		send_bin(av[2][i],num);
		i++;
	}
	write (1, "alls good\n", ft_strlen("alls good\n"));
}