/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:01:24 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/12 13:01:25 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_buffer	g_buffer;

int	main(void)
{
	g_buffer.index = 0;
	g_buffer.character = 0;
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, &print_1);
	signal(SIGUSR2, &print_2);
	while (1)
	{
		continue ;
	}
}

void	print_1(int sig)
{
	(void)sig;
	g_buffer.character |= (1 << (7 - g_buffer.index));
	g_buffer.index++;
	verif();
}

void	print_2(int sig)
{
	(void)sig;
	g_buffer.character &= ~(1 << (7 - g_buffer.index));
	g_buffer.index++;
	verif();
}

void	verif(void)
{
	if (g_buffer.index == 8)
	{
		g_buffer.index = 0;
		ft_printf("%c", g_buffer.character);
		g_buffer.character = 0;
	}
}
