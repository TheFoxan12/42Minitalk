/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:01:02 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/12 13:01:03 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("arguments error\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	send_string_in_bit(argv[2], pid);
	return (0);
}

void	send_char_in_bit(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(50);
	}
}

void	send_string_in_bit(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char_in_bit(str[i], pid);
		i++;
	}
}
