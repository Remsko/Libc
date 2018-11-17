NAME = libft.a
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./incs
SRC_PATH = srcs/
SRC_NAME =	memory/ft_memset.c \
		string/ft_strlen.c \
		string/ft_strnlen.c \

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME)) 

all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)memory
	@mkdir -p $(OBJ_PATH)string

$(NAME): $(OBJ_PATH) $(OBJ)
	@ar -rc $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
