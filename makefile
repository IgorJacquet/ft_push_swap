# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igor <igor@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 15:27:21 by igor              #+#    #+#              #
#    Updated: 2021/03/31 00:57:01 by igor             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHK		=	checker

NAME_PSWP		=	push_swap

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address

LIBFT			=	libft/libft.a

SRCS_NAME_CHK	=	checker.c \
					reader.c \
					operations_swap.c \
					operations_push.c \
					operations_rotate.c \
					parsing.c \
					utils.c \

SRCS_NAME_PSWP	=	push_swap.c \
					utils.c \
					parser.c \
					operations_swap.c \
					operations_push.c \
					operations_rotate_1.c \
					operations_rotate_2.c \
					checkers.c \
					display.c \
					fill_stack_a.c \
				
INC_NAME_CHK	= 	checker.h \

INC_NAME_PSWP	= 	push_swap.h \

SRCS_CHK		=	$(addprefix srcs_chk/, $(SRCS_NAME_CHK))

SRCS_PSWP		=	$(addprefix srcs_pswp/, $(SRCS_NAME_PSWP))

INC_CHK			=	$(addprefix includes/, $(INC_NAME_CHK))

INC_PSWP		=	$(addprefix includes/, $(INC_NAME_PSWP))

OBJS_CHK		= 	$(SRCS_CHK:.c=.o)

OBJS_PSWP		= 	$(SRCS_PSWP:.c=.o)

all : $(NAME_CHK) $(NAME_PSWP)

$(NAME_CHK) : $(OBJS_CHK) $(LIBFT) $(INC_CHK)
			$(CC) $(CFLAGS) $(OBJS_CHK) $(LIBFT) -o $(NAME_CHK) -lncurses

$(NAME_PSWP) : $(OBJS_PSWP) $(LIBFT) $(INC_PSWP)
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
