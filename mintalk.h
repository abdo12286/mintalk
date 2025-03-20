#ifndef MINTALK_H
# define MINTALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>


int	ft_strlen(char *str);
void	put_err(char *str);
int	ft_atoi(char *str);
void	send_bin(unsigned char av, pid_t num);
#endif