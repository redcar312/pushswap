# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 19:38:50 by mhurtamo          #+#    #+#              #
#    Updated: 2025/02/16 20:01:25 by mhurtamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= arg_parser.c base_commands.c main.c p_and_s_commands.c parser_utils.c reverse_rotate.c rotate.c solver.c solver_rotators.c solver_utils.c stack_utils.c ft_calloc.c

HEAD	= ./

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

RM	= rm -f

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

c.o: ${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}



${NAME}: ${OBJS}
	${CC} ${CFLAGS} -g ${OBJS} -o ${NAME}
	
clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all bonus clean



.PHONY:	all clean fclean re bonus
