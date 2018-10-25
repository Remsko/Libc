NAME = libft.a
CC = gcc
RM = rm -rf
CFLAGS = -c -Wall -Werror -Wextra
SRC =  \

OBJ_PATH = obj/
OBJ_NAME = $(SRC:.c=.o)
	OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME)) 

all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ_PATH) $(OBJ)
	@ar -rc $(NAME) $(OBJ)

$(OBJ_PATH)%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
