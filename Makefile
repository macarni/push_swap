# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 13:52:47 by adrperez          #+#    #+#              #
#    Updated: 2023/03/22 18:42:09 by adrperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Exit
NAME		= 	push_swap

#Sources
SRCS		= 	src/push_swap.c \
			 	src/swap.c \
			 	src/push.c \
			 	src/rotate.c \
			 	src/lists.c \
			 	src/args.c \
				utils/ft_atoi.c \
				utils/ft_split.c \
				utils/ft_strlcpy.c \
				utils/ft_strlen.c \
				utils/ft_isdigit.c \

FT_PRINTF_PATH = utils/ft_printf/
				
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
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INC) -I$(FT_PRINTF_PATH)
		
$(NAME): 	$(OBJS)
			@make -C $(FT_PRINTF_PATH) --silent
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I../ft_printf -L./utils/ft_printf/ -lftprintf 

#Cleaning objects (Eliminacion de objetos)
clean:
			$(RM) $(OBJS)
			@make -C $(FT_PRINTF_PATH) clean --silent

#Cleaning objects and executable 
fclean:		clean
			$(RM) $(NAME) $(OBJS)
			@make -C $(FT_PRINTF_PATH) fclean --silent

#Cleaning all and then compilation
re:			fclean all

#Exectute no matter name is
.PHONY: all clean fclean re bonus