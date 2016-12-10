# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achan <achan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 13:03:37 by achan             #+#    #+#              #
#    Updated: 2016/12/09 22:39:36 by achan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRS	=	hdrs
SRCS	=	srcs
OBJS	=	objs
CC		=	gcc
WFLAGS	=	-Wall -Wextra -Werror
CFLAGS	=	-c
GFLAGS	=	
IFLAGS	=	-I $(HDRS)
C_SRCS	=	$(wildcard $(SRCS)/*.c)
C_OBJS	=	$(addprefix $(OBJS)/, $(notdir ${C_SRCS:.c=.o}))
NAME	=	fillit

.PHONY:		all clean fclean re

all: $(NAME)

$(NAME): $(C_OBJS)
	$(CC) $(WFLAGS) $(GFLAGS) $(IFLAGS) -L. -lft $(C_OBJS) -o $@

$(C_OBJS): $(C_SRCS)
	mkdir -p $(OBJS)
	$(CC) $(WFLAGS) $(IFLAGS) $(GFLAGS) $(CFLAGS) $(subst $(OBJS),$(SRCS),$*.c) -o $@

clean:		
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
