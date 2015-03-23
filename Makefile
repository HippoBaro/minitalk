##
## Makefile for minitalk in /home/barrau_h
## 
## Made by Hippolyte Barraud
## Login   <barrau_h@epitech.net>
## 
## Started on  Fri Feb 27 21:38:08 2015 Hippolyte Barraud
## Last update Wed Mar  4 02:16:03 2015 Hippolyte Barraud
##

CC              =       gcc

SERVER		=	server

CLIENT		=	client

SRCGEN		=	./src/common/str_utils.c	\
			./src/common/xmalloc.c		\
			./src/common/hash.c

SRCS		=	./$(SERVER)/src/main.c		\
			./$(SERVER)/src/transaction.c	\
			./$(SERVER)/src/transfer.c

SRCC		=	./$(CLIENT)/src/main.c			\
			./$(CLIENT)/src/check_arg.c		\
			./$(CLIENT)/src/transaction.c		\
			./$(CLIENT)/src/bonus.c			\
			./$(CLIENT)/src/printer.c		\
			./$(CLIENT)/src/transmision.c		\
			./$(CLIENT)/src/binary.c		\

OBJSS		=	$(SRCS:.c=.o)

OBJSC		=	$(SRCC:.c=.o)

OBJGEN		=	$(SRCGEN:.c=.o)

CFLAGS          =       -Wall -Wextra -Werror -pedantic -O0

RM              =       rm -f

all		:	$(SERVER) $(CLIENT)

$(CLIENT)	:	$(OBJSC) $(OBJGEN)
			$(CC) -o $(CLIENT)/$(CLIENT) $(OBJSC) $(OBJGEN)

$(SERVER)	:	$(OBJSS) $(OBJGEN)
			$(CC) -o $(SERVER)/$(SERVER) $(OBJSS) $(OBJGEN)

clean		:
			$(RM) $(OBJSS) $(OBJSC) $(OBJGEN) 

fclean		:	clean
			$(RM) $(SERVER)/$(SERVER) $(CLIENT)/$(CLIENT)

re		:	fclean all

.PHONY 		: 	all clean re
