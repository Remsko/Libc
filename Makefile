NAME = libft.a
CC = gcc
RM = rm -rf

INC_PATH = incs
INC_NAME += libft.h
INC_NAME += memory_42.h
INC_NAME += string_42.h
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = $(addprefix -I,$(INC_PATH))

SRC_PATH = srcs
SRC_SUB += memory
SRC_SUB += string
vpath %.c $(addprefix $(SRC_PATH)/, $(SRC_SUB))

SRC_NAME +=	ft_memset.c
SRC_NAME +=	ft_memchr.c

SRC_NAME += ft_strlen.c
SRC_NAME += ft_strnlen.c
SRC_NAME += ft_strdup.c
SRC_NAME += ft_strndup.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME)) 

all: $(NAME)


$(NAME): $(OBJ)
	ar -rc $@ $^

$(OBJ): $(OBJ_PATH) | $(INC)
$(OBJ): $(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	mkdir -p $@

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
