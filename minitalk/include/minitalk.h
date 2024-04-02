/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:02:10 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/12 13:02:10 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "../include/ft_printf.h"
# include <signal.h>

typedef struct s_buffer {
	int		character;
	int		index;
}	t_buffer;

int		ft_atoi(char *str);
void	send_char_in_bit(char c, int pid);
void	send_string_in_bit(char *str, int pid);
void	print_1(int sig);
void	print_2(int sig);
void	verif(void);

#endif //MINITALK_H
