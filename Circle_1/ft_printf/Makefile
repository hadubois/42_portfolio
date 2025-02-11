CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_FILES = ft_printf.c ft_utils.c 
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_FILES)
	$(AR) csr $@ $^ 

clean :
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
