NAME = visualizer

CC = gcc
CFLAGS = -W -Wall -Wextra -Werror

DEBUG =
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

MLX_DIR = Libs/minilibx_opengl_20191021/
LIBFT_DIR = ./Libs/libft_duck/
GETFILE_DIR = Libs/Lib_get_file/
INC_DIR = ./Includes/push_swap_visualizer
OBJS_DIR = Objs
SRCS_DIR = $(shell find Srcs -type d)

LIBS = -L$(LIBFT_DIR) -L$(GETFILE_DIR) -L$(MLX_DIR)
INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)/Includes -I$(GETFILE_DIR)/Includes -I$(INC_DIR)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

SRCS = main.c \
	visualizer_manager.c visualizer_mlx_print.c \
	stack_single_operations.c stack_multi_operations.c \
	stack_managment.c stack_search.c stack_length.c \
	error_manager.c
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: Libs/libft_duck/libft.a Libs/Lib_get_file/libgetfile.a Libs/minilibx_opengl_20191021/libmlx.a $(NAME)

Libs/minilibx_opengl_20191021/libmlx.a:
	make -C $(MLX_DIR) all

Libs/libft_duck/libft.a:
	make -C $(LIBFT_DIR) all

Libs/Lib_get_file/libgetfile.a:
	make -C $(GETFILE_DIR) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) -lft -lgetfile -lmlx -framework OpenGL -framework AppKit

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

allre: cleanall all

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf  $(NAME)

cleanall: fclean
	make -C $(MLX_DIR) fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(GETFILE_DIR) fclean

.PHONY : clean fclean cleanall re allre all