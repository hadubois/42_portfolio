# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadubois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 15:31:36 by hadubois          #+#    #+#              #
#    Updated: 2025/01/09 13:40:26 by hadubois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all 

INCLUDE = ./include/
SRC_DIR = ./src/
OBJ_DIR = ./obj/
ARGS =

SRC_FILES = algorithm.c\
			\
			utils/ft_split.c utils/ft_atol.c utils/args_tester.c \
			utils/free_all.c utils/ft_strtrim.c \
			printf/ft_utils.c printf/ft_printf.c \
			\
			moves/push.c moves/swap.c moves/reverse_rotate.c moves/rotate.c \
			\
			list_utils/sort_three_last_args.c list_utils/do_best_move.c\
			list_utils/fill_stack.c list_utils/print_lists.c \
			list_utils/chain_list_utils1.c list_utils/chain_list_utils2.c
OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# Définition des couleurs ANSI
RESET   = \033[0m
GREEN   = \033[32m
RED     = \033[31m

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	@ $(CC) $(CFLAGS) -I$(INCLUDE) -o $@ $^
	@ echo "$(NAME) $(GREEN)READY$(RESET)"
#	@ ./$(NAME) $(ARGS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	@ $(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

$(OBJ_DIR) :
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(OBJ_DIR)utils
	@ mkdir -p $(OBJ_DIR)list_utils
	@ mkdir -p $(OBJ_DIR)moves
	@ mkdir -p $(OBJ_DIR)printf

v:
	$(VALGRIND) ./$(NAME) $(ARGS)
clean :
	@ $(RM) $(OBJ_FILES)
	@ $(RM) -rf $(OBJ_DIR)
	@ echo "clean $(GREEN)O.K$(RESET)"

fclean : clean
	@ $(RM) $(NAME)
	@ echo "fclean $(GREEN)O.K$(RESET)"

re : fclean all

.PHONY : all clean fclean re v
