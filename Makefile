# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 13:16:07 by ysahnoun          #+#    #+#              #
#    Updated: 2026/01/24 11:42:37 by ysahnoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

MANDATORY		= ft_atoi.c ft_split.c helper1.c push_swap.c push.c revrotate.c \
				rotate.c swap.c  sortAlgo.c sortAlgo1.c sort.c chunk.c

SRC         = $(MANDATORY)
OBJS        = $(SRC:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

#AR          = ar rcs
RM          = rm -f

# --- Rules ---

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(CFLAGS)  $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean 