NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

DEBUG =
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

LIBFT_DIR = Libs/libft/
INC_DIR = ./Includes/push_swap
OBJS_DIR = Objs
SRCS_DIR = $(shell find Srcs -type d)
LIBS = -L$(LIBFT_DIR)
INCLUDES = -I$(LIBFT_DIR)/Includes -I$(INC_DIR)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

SRCS = init.c \
		debug_print.c error_manager.c \
		stack_id_monitoring.c stack_managment.c \
		stack_multi_operations.c stack_single_operations.c \
		algorythm_execute.c algorythm_manager.c algorythm_utils.c
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

allre: cleanall all

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

cleanall: fclean
	make -C $(LIBFT_DIR) fclean

.PHONY : clean fclean cleanall re allre all install