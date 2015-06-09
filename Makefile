##
## Makefile for  in /home/mart_4/rendu/TestPiscine/minione
##
## Made by Thomas Martins
## Login   <mart_4@epitech.net>
##
## Started on  Mon Jan 26 23:47:17 2015 Thomas Martins
## Last update Sun Mar 29 14:09:15 2015 Thomas Martins
##

SRC	= src/read/get_env.c \
	src/read/pid.c \
	src/word_tab/str_cat.c \
	src/basic/func_all.c \
	main.c \
	src/basic/my_getnbr.c \
	src/basic/strncmp.c \
	src/word_tab/str_to_word_tab.c \
	src/read/read_shell.c \
	src/basic/my_strcmp.c \
	src/read/prompt.c \
	src/printf/function_one.c \
	src/printf/my_function.c \
	src/printf/my_putnbr_base.c \
	src/printf/my_printf.c \
	src/printf/my_putnbr_flag.c \
	src/printf/printf_two.c \
	src/read/get_env_next.c \
	src/read/my_cd.c \
	src/word_tab/new_str_word_tab.c \
	src/basic/help.c \
	src/read/redirect.c \
	src/basic/epur_str.c \
	src/read/call_builtin.c

OBJ	= $(SRC:.c=.o)

NAME	= mysh

RM	= rm -f

CFLAGS	:= -pedantic
CFLAGS	+= -W -Wall

CC	= cc

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
