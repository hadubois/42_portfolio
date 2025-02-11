# **************************************************************************** #
#                                   MAKEFILE                                   #
# **************************************************************************** #
MAKEFLAGS += --no-print-directory

RESET   = \033[0m
GREEN   = \033[32m
RED     = \033[31m

NAME = pipex
SRCDIR = src
OBJDIR = obj
INCDIR = include

SRC = pipex.c pipex_utils.c handle_execve.c handle_error.c

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	@ cd ./lib/libft && make
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./lib/libft -lft
	@ echo "\n┌―――――――――――――――――――――――――――┐"
	@ echo "│        pipex $(GREEN)READY$(RESET)        │"
	@ echo "└―――――――――――――――――――――――――――┘\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@ mkdir -p $(OBJDIR)

clean:
	@ cd ./lib/libft && make clean
	@ rm -rf $(OBJDIR)
	@ echo "clean $(GREEN)O.K$(RESET)"

fclean: clean
	@ cd ./lib/libft && make fclean
	@ rm -f $(NAME)
	@ echo "fclean $(GREEN)O.K$(RESET)"

re: fclean all

.PHONY: all clean fclean re
