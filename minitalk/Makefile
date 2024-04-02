# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 10:23:53 by ^@^ Foxan ^@^     #+#    #+#              #
#    Updated: 2022/11/24 11:27:32 by ^@^ Foxan ^@^    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

CC			:= gcc
NAME		:= minitalk
CFLAGS		:= -Wextra -Wall -Werror

HEADERS		:= -I include/minitalk.h
LIBFTPRINTF	:= ./ft_printf
LIBS		:= $(LIBFTPRINTF)/libftprintf.a

SRCS		:= src/ft_atoi.c
OBJS		:= ${SRCS:.c=.o}

CLIENTSRC	:= src/client.c
CLIENTOBJ	:= ${CLIENTSRC:.c=.o}

SERVERSRC	:= src/server.c
SERVEROBJ	:= ${SERVERSRC:.c=.o}

all: libftprintf $(NAME)
	@printf "$(MAGENTA)Done !\n$(RESET)"

#//= Compiling source files =//#
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(MAGENTA)$(NAME)$(RESET)$(BOLD) Compiling: $(notdir $<) \n$(RESET)"

$(NAME): start $(OBJS) $(CLIENTOBJ) $(SERVEROBJ) end
	@printf "$(MAGENTA)Compiling everything...\n$(RESET)"
	@$(CC) -o client $(CLIENTOBJ) $(OBJS) $(LIBS) $(HEADERS)
	@$(CC) -o server $(SERVEROBJ) $(OBJS) $(LIBS) $(HEADERS)
	@printf "$(BOLD)Done compiling $(MAGENTA)e$(CYAN)v$(GREEN)e$(YELLOW)r$(BLUE)y$(RED)t$(MAGENTA)h$(CYAN)i$(GREEN)n$(YELLOW)g !\n$(RESET)"
	@printf "$(BOLD)--------------------\n$(RESET)"

start:
	@printf "$(MAGENTA)Making $(NAME)...\n$(RESET)"

end:
	@printf "$(BOLD)Done making $(MAGENTA)$(NAME)\n$(RESET)"
	@printf "$(BOLD)--------------------\n$(RESET)"

libftprintf:
	@printf "$(MAGENTA)Making FTPRINTF...\n$(RESET)" && $(MAKE) -C $(LIBFTPRINTF)
	@printf "$(BOLD)Done making $(MAGENTA)FTPRINTF\n$(RESET)"
	@printf "$(BOLD)--------------------\n$(RESET)"

#//= Cleaning rules =//#
clean:
	@rm -f $(SERVEROBJ) && rm -f $(CLIENTOBJ) && rm -f $(OBJS) && printf "$(BLUE)Cleaning $(NAME)...\n$(RESET)"
	@$(MAKE) -C $(LIBFTPRINTF) clean
	@printf "$(YELLOW)Finished cleaning !\n$(RESET)"

fclean: clean
	@printf "$(BOLD)--------------------\n$(RESET)"
	@rm -f client && rm -f server && rm -f $(OBJS) && printf "$(BLUE)Fully Cleaning $(NAME)...\n$(RESET)"
	@$(MAKE) -C $(LIBFTPRINTF) fclean
	@printf "$(YELLOW)Finished cleaning everything !\n$(RESET)"

re: fclean all

.PHONY: $(NAME), all, start, end, clean, fclean, re
