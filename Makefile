NAME = libft.a
CC = gcc
RM = rm -rf

INC_PATH += ./incs

INC_NAME += memory_42.h
INC_NAME += string_42.h
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = $(addprefix -I,$(INC_PATH))

SRC_PATH = srcs

SRC_SUB += memory
SRC_NAME +=	ft_mempcpy.c
SRC_NAME +=	ft_memccpy.c
SRC_NAME +=	ft_memset.c
SRC_NAME +=	ft_memchr.c
SRC_NAME +=	ft_bzero.c

SRC_SUB += string
SRC_NAME += ft_strlen.c
SRC_NAME += ft_strnlen.c
SRC_NAME += ft_strdup.c
SRC_NAME += ft_strndup.c
SRC_NAME += ft_strcat.c
SRC_NAME += ft_strncat.c
SRC_NAME += ft_strcmp.c
SRC_NAME += ft_strncmp.c
SRC_NAME += ft_strcpy.c
SRC_NAME += ft_strncpy.c

vpath %.c $(addprefix $(SRC_PATH)/, $(SRC_SUB))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME)) 

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $^

$(OBJ): $(INC) | $(OBJ_PATH)
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
