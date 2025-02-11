NAME = so_long

RESET   = \033[0m
GREEN   = \033[32m
RED     = \033[31m

SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = lib/libft/
MLXDIR	= lib/minilibx-linux

CHECKERDIR = $(SRCDIR)/map_checker/
UTILSDIR = $(SRCDIR)/utils/
GRAPHICSDIR = $(SRCDIR)/graphics/

CHECKER_SRC = $(CHECKERDIR)find_path.c $(CHECKERDIR)is_map_ok.c\
			  $(CHECKERDIR)map_utils1.c $(CHECKERDIR)map_utils2.c
UTILS_SRC = $(UTILSDIR)free_all.c
GRAPHICS_SRC = $(GRAPHICSDIR)set_display.c $(GRAPHICSDIR)handle_key.c

SRC = $(SRCDIR)/main.c $(CHECKER_SRC) $(UTILS_SRC) $(GRAPHICS_SRC)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -L./lib/minilibx-linux -lmlx -lXext -lX11 -lm

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# mac
	CC = clang
else ifeq ($(UNAME), FreeBSD)
	# FreeBSD
	CC = clang
else
	#Linux and others...
	CC	= gcc
	LFLAGS += -lbsd
endif

all: $(NAME)

$(NAME): $(OBJ)
	@ cd $(MLXDIR) && make
	@ cd $(LIBFTDIR) && make
	@ $(CC) -o $(NAME) $(OBJ) -L./lib/libft -lft $(LFLAGS)
	@ echo "SO_LONG $(GREEN)READY$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@ cd $(LIBFTDIR) && make clean
	@ rm -rf $(OBJDIR)
	@ echo "clean $(GREEN)O.K$(RESET)"

fclean: clean
	@ cd $(LIBFTDIR) && make fclean
	@ rm -f $(NAME)
	@ echo "fclean $(GREEN)O.K$(RESET)"

re: fclean all

.PHONY: all clean fclean re
