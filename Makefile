NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

DEBUG =
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

LIBFT_DIR = libft/
OBJS_DIR = Objs
LIBS = -L$(LIBFT_DIR)
INCLUDES = -I$(LIBFT_DIR)/Includes -Ipush_swap.h
SRCS = debug_print.c main.c list_managment.c \
		stack_managment.c stack_single_operations.c \
		stack_multi_operations.c
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: libft/libft.a $(NAME)

libft/libft.a:
	make -C $(LIBFT_DIR) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $@ $(LIBS) -lft

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

cleanall: fclean
	make -C $(LIBFT_DIR) clean

.PHONY : clean fclean cleanall re all install