NAME = libft.a
CC = gcc
RM = rm -rf

INC_PATH += ./incs

INC_NAME += array_42.h
INC_NAME += ascii_42.h
INC_NAME += conv_42.h
INC_NAME += error_42.h
INC_NAME += free_42.h
INC_NAME += libft.h
INC_NAME += list_42.h
INC_NAME += math_42.h
INC_NAME += memory_42.h
INC_NAME += queue_42.h
INC_NAME += read_42.h
INC_NAME += string_42.h
INC_NAME += write_42.h
INC_NAME += error_42.h
INC_NAME += free_42.h
INC_NAME += rb_tree_42.h


INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = $(addprefix -I,$(INC_PATH))

SRC_PATH = srcs

SRC_SUB += memory
SRC_NAME += ft_memalloc.c
SRC_NAME += ft_realloc.c
SRC_NAME +=	ft_memchr.c
SRC_NAME += ft_memdel.c
SRC_NAME += ft_memcpy.c
SRC_NAME += ft_memmove.c
#SRC_NAME += ft_memcmp.c
SRC_NAME +=	ft_mempcpy.c
SRC_NAME +=	ft_memccpy.c
SRC_NAME +=	ft_memset.c
SRC_NAME +=	ft_bzero.c

SRC_SUB += memory/wordcopy
SRC_NAME += wordcopy_fwd_aligned.c
SRC_NAME += wordcopy_fwd_dest_aligned.c
SRC_NAME += wordcopy_bwd_aligned.c
SRC_NAME += wordcopy_bwd_dest_aligned.c

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
SRC_NAME += ft_strchr.c
SRC_NAME += ft_strrchr.c
SRC_NAME += ft_strdel.c
SRC_NAME += ft_strequ.c
SRC_NAME += ft_strnequ.c
SRC_NAME += ft_strjoin.c
SRC_NAME += ft_strsub.c
SRC_NAME += ft_strwords.c
SRC_NAME += ft_strsplit.c
SRC_NAME += ft_splitlen.c

SRC_SUB += ascii
SRC_NAME += ft_isascii.c
SRC_NAME += ft_isalnum.c
SRC_NAME += ft_isalpha.c
SRC_NAME += ft_isdigit.c
SRC_NAME += ft_isprint.c
SRC_NAME += ft_isspace.c
SRC_NAME += ft_tolower.c
SRC_NAME += ft_toupper.c

SRC_SUB += math
SRC_NAME += is_pwrof2.c
SRC_NAME += next_pwrof2.c

SRC_SUB += array
SRC_NAME += array_create.c
SRC_NAME += array_resize_maybe.c
SRC_NAME += array_index.c
SRC_NAME += array_append.c
SRC_NAME += array_dispose.c
SRC_NAME += array_insert.c
SRC_NAME += array_fit.c

SRC_SUB += list
SRC_NAME += list_head_init.c
SRC_NAME += list_insert.c
SRC_NAME += list_del.c
SRC_NAME += list_add.c

SRC_SUB += conv
SRC_NAME += ft_itoa.c
SRC_NAME += ft_atoi.c
SRC_NAME += ft_isatoi.c

SRC_SUB += read
SRC_NAME += get_next_line.c
SRC_NAME += read_file.c

SRC_SUB += write
SRC_NAME += ft_putchar.c
SRC_NAME += ft_putchar_fd.c
SRC_NAME += ft_putendl.c
SRC_NAME += ft_putendl_fd.c
SRC_NAME += ft_putnbr.c
SRC_NAME += ft_putnbr_fd.c
SRC_NAME += ft_putstr.c
SRC_NAME += ft_putstr_fd.c

SRC_SUB += error
SRC_NAME += error_malloc.c
SRC_NAME += error_create.c
SRC_NAME += error_throw.c
SRC_NAME += malloc_or_die.c

SRC_SUB += free
SRC_NAME += free_2d_char.c

SRC_SUB += queue
SRC_NAME += new_qnode.c
SRC_NAME += create_queue.c
SRC_NAME += de_queue.c
SRC_NAME += en_queue.c
SRC_NAME += is_queue.c

SRC_SUB += rb_tree
SRC_NAME += rb_tree_new_node.c


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
