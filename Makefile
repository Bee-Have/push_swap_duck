CC = gcc
CFLAGS = -Wall -Wextra -Werror

DEBUG =
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

NAME = push_swap
LIBFT_DIR = libft/
LIBS = -L$(LIBFT_DIR)
INCLUDES = -I$(LIBFT_DIR) -Ipush_swap.h
SRCS = debug_print.c main.c push_swap.c list_managment.c \
		stack_managment.c stack_single_operations.c \
		stack_multi_operations.c
OBJS = $(SRCS:.c=.o)

all: install $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

install:
	cp $(LIBFT_DIR) && $(MAKE) all

$(NAME): $(OBJS)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	$(CC) $(CFLAGS) -o $@ $(LIBS) $(INCLUDES)

clean:
	rm -f *.o
	cd libft/ && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd libft/ && $(MAKE) fclean

re: fclean all

.PHONY : clean fclean re all install