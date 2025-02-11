NAME = libft.a

RESET   = \033[0m
GREEN   = \033[32m
RED     = \033[31m

SRCDIR = src
OBJDIR = obj
INCDIR = include

LIBFTDIR = $(SRCDIR)/libft/
GNLDIR = $(SRCDIR)/get_next_line/
PRINTF_DIR = $(SRCDIR)/ft_printf/

LIBFT_SRC = $(LIBFTDIR)ft_isalpha.c $(LIBFTDIR)ft_isdigit.c $(LIBFTDIR)ft_isalnum.c $(LIBFTDIR)ft_isascii.c \
			$(LIBFTDIR)ft_isprint.c $(LIBFTDIR)ft_strlen.c $(LIBFTDIR)ft_memset.c $(LIBFTDIR)ft_bzero.c \
			$(LIBFTDIR)ft_memcpy.c $(LIBFTDIR)ft_memmove.c $(LIBFTDIR)ft_strlcpy.c $(LIBFTDIR)ft_strlcat.c \
			$(LIBFTDIR)ft_toupper.c $(LIBFTDIR)ft_tolower.c $(LIBFTDIR)ft_strrchr.c \
			$(LIBFTDIR)ft_strncmp.c $(LIBFTDIR)ft_memchr.c $(LIBFTDIR)ft_memcmp.c $(LIBFTDIR)ft_strnstr.c\
			$(LIBFTDIR)ft_atoi.c $(LIBFTDIR)ft_calloc.c $(LIBFTDIR)ft_substr.c \
			$(LIBFTDIR)ft_strtrim.c $(LIBFTDIR)ft_split.c $(LIBFTDIR)ft_itoa.c \
			$(LIBFTDIR)ft_strmapi.c $(LIBFTDIR)ft_striteri.c $(LIBFTDIR)ft_putchar_fd.c $(LIBFTDIR)ft_putstr_fd.c \
			$(LIBFTDIR)ft_putendl_fd.c $(LIBFTDIR)ft_putnbr_fd.c
GNL_SRC = $(GNLDIR)get_next_line.c $(GNLDIR)get_next_line_utils.c
PRINTF_SRC = $(PRINTF_DIR)ft_printf.c $(PRINTF_DIR)ft_utils.c

SRC = $(LIBFT_SRC) $(GNL_SRC) $(PRINTF_SRC)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@ $(AR) $(NAME) $(OBJ)
	@ echo "libft $(GREEN)O.K$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@ rm -rf $(OBJDIR)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

