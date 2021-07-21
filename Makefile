NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

VISUAL =

ifdef VISUAL
CFLAGS += -W
endif

DEBUG =
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

LIBFT_DIR = Libs/libft/
MLX_DIR = Libs/minilibx_opengl_20191021/
INC_DIR = ./Includes/push_swap
OBJS_DIR = Objs
SRCS_DIR = $(shell find Srcs -type d)

ifdef VISUAL
LIBS = -L$(LIBFT_DIR) -L$(MLX_DIR)
INCLUDES = -I$(LIBFT_DIR)/Includes -I$(MLX_DIR) -I$(INC_DIR)
else
LIBS = -L$(LIBFT_DIR)
INCLUDES = -I$(LIBFT_DIR)/Includes -I$(INC_DIR)
endif

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

SRCS = debug_print.c error_manager.c \
		stack_search.c stack_length.c stack_managment.c \
		stack_multi_operations.c stack_single_operations.c \
		algorythm_execute.c algorythm_manager.c \
		algorythm_moves_calculator.c algorythm_finish.c algorythm_utils.c \
		main.c
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

ifdef VISUAL
SRCS_VISU = visualizer_manager.c visualizer_mlx_print.c #\
			#tests.c
OBJS_VISU = $(addprefix $(OBJS_DIR)/,$(SRCS_VISU:.c=.o))
endif

ifdef VISUAL
all: Libs/libft/libft.a Libs/mlx/libmlx.a $(NAME)
endif

all: Libs/libft/libft.a $(NAME)

Libs/mlx/libmlx.a:
	make -C $(MLX_DIR) all

Libs/libft/libft.a:
	make -C $(LIBFT_DIR) all

ifdef VISUAL
$(NAME): $(OBJS_VISU) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit
else
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) -lft
endif

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

allre: cleanall all

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

ifdef VISUAL
cleanall: fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
else
cleanall: fclean
	make -C $(LIBFT_DIR) fclean
endif

.PHONY : clean fclean cleanall re allre all install
