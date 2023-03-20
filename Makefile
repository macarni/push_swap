# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 13:52:47 by adrperez          #+#    #+#              #
#    Updated: 2023/03/20 10:48:10 by adrperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Exit
NAME		= 	push_swap

#Sources
SRCS		= 	src/push_swap.c \
				utils/ft_atoi.c
				
OBJS		= 	$(SRCS:.c=.o)

#Compilation
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

#Include
INC			= ./include

#Erase
RM			= 	rm -rf

#Default target
all:		$(NAME)
			
%.o:%.c
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INC)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)		

#Cleaning objects (Eliminacion de objetos)
clean:
			$(RM) $(OBJS)

#Cleaning objects and executable 
fclean:		clean
			$(RM) $(NAME) $(OBJS)

#Cleaning all and then compilation
re:			fclean all

#Exectute no matter name is
.PHONY: all clean fclean re bonus