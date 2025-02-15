# ================================[ CONFIG ]================================== #
NAME = philo

SRCDIR = src
OBJDIR = obj
INCDIR = include

SRC = main.c \
	  parsing.c \
	  init_utils.c \
	  routine.c \
	  search_dead.c \
	  philo_utils.c \
	  cleanup_utils.c \
	  utils.c
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

CC         = cc
CFLAGS     = -g -pthread -Wall -Wextra -Werror -I$(INCDIR)
MAKEFLAGS += --no-print-directory

# ================================[ DRAWING ]================================= #
RESET = \033[0m
GREEN = \033[32m
RED   = \033[31m

UP_LINE   = "┌───────────────────────────┐"
DOWN_LINE = "└───────────────────────────┘"
SIDE_L    = │
L_ARROW   = ❯

# ===============================[ RECIPIES ]================================= #
all: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@ echo $(UP_LINE)
	@ echo "$(SIDE_L)        $(NAME) $(GREEN)READY$(RESET)        $(SIDE_L)"
	@ echo $(DOWN_LINE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@ mkdir -p $(OBJDIR)
clean:
	@ rm -rf $(OBJDIR)
	@ echo "$(L_ARROW) clean $(GREEN)O.K$(RESET)"

fclean: clean
	@ rm -f $(NAME)
	@ echo "$(L_ARROW) fclean $(GREEN)O.K$(RESET)"

re: fclean all

# =============================[ PHONY TARGETS ]============================== #
.PHONY: all clean fclean re
