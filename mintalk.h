/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mintalk.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:45:15 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/21 17:45:16 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINTALK_H
# define MINTALK_H

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int		ft_strlen(char *str);
void	put_err(char *str);
int		ft_atoi(char *str);
void	send_bin(unsigned char av, pid_t num);
#endif