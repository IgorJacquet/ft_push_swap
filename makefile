# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igor <igor@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 15:27:21 by igor              #+#    #+#              #
#    Updated: 2021/03/29 20:57:26 by igor             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHK		=	checker

NAME_PSWP		=	push_swap

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address

LIBFT			=	libft/libft.a

SRCS_NAME_CHK	=	checker.c \

SRCS_NAME_PSWP	=	push_swap.c \
				
INC_NAME		= 	checker.h \

SRCS_CHK		=	$(addprefix srcs_chk/, $(SRCS_NAME_CHK))

SRCS_PSWP		=	$(addprefix srcs_pswp/, $(SRCS_NAME_PSWP))

INC				=	$(addprefix includes/, $(INC_NAME))

OBJS_CHK		= 	$(SRCS_CHK:.c=.o)

OBJS_PSWP		= 	$(SRCS_PSWP:.c=.o)

all : $(NAME_CHK) $(NAME_PSWP)

$(NAME_CHK) : $(OBJS_CHK) $(LIBFT) $(INC)
			$(CC) $(CFLAGS) $(OBJS_CHK) $(LIBFT) -o $(NAME_CHK) -lncurses

$(NAME_PSWP) : $(OBJS_PSWP) $(LIBFT) $(INC)
			$(CC) $(CFLAGS) $(OBJS_PSWP) $(LIBFT) -o $(NAME_PSWP) -lncurses

$(LIBFT) : 
			make -C libft all

clean :
			rm -f $(OBJS_CHK) $(OBJS_PSWP)
			make -C libft clean

fclean :	clean
			rm -f $(NAME_CHK) $(NAME_PSWP)
			make -C libft fclean

re: fclean all
