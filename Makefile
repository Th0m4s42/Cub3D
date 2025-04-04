NAME := cub3D
CC := cc
FLAGS := -MMD -Wall -Werror -Wextra -g3

MLX_INCLUDES = -I/opt/X11/include -Iminilibx-linux
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_DIR := minilibx-linux/

Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

SRC_DIR := mandatory_srcs/
OBJ_DIR := objs/


PARSING := parsing/
RAYCASTING := raycasting/
GAME := game/
KEY_EVENT := key_event/
EXIT := exit/

SRCS := \
	$(SRC_DIR)main.c \
	\
	$(SRC_DIR)$(PARSING)check_args.c \
	$(SRC_DIR)$(PARSING)ft_parsing.c \
	\
	$(SRC_DIR)$(PARSING)save_path_textures.c \
	$(SRC_DIR)$(PARSING)save_color_background.c \
	\
	$(SRC_DIR)$(PARSING)utils_parsing.c \
	$(SRC_DIR)$(PARSING)utils_realloc.c \
	$(SRC_DIR)$(PARSING)utils_check_id.c \
	\
	$(SRC_DIR)$(PARSING)ft_check_hole.c \
	$(SRC_DIR)$(PARSING)ft_checker_map.c \
	\
	$(SRC_DIR)$(EXIT)free_visuals.c \
	\
	$(SRC_DIR)$(RAYCASTING)DDA.c \
	\
	$(SRC_DIR)$(GAME)player.c \
	$(SRC_DIR)$(GAME)draw_game.c \
	$(SRC_DIR)$(GAME)draw_map.c \
	$(SRC_DIR)$(GAME)draw_game2.c \
	$(SRC_DIR)$(GAME)utils_game.c \
	\
	$(SRC_DIR)$(KEY_EVENT)key_event.c \
	$(SRC_DIR)$(KEY_EVENT)movements.c \
	$(SRC_DIR)$(KEY_EVENT)rotation.c \
	\

LIBFT_DIR := libft/
LIBFT_LIB := libft/libft.a
LIBFT := -L $(LIBFT_DIR) -lft
LIBFT_FLAGS := -Llibft -l:libft.a

INCLUDES := -I includes

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

DEP		:= $(OBJS:.o=.d)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "$(Cyan)Compiling $<...$(White)"

$(NAME) : $(OBJS)
	make -C libft/
	make -C minilibx-linux/
	@$(CC) $(FLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -lm
	@echo "$(Green)$(NAME) CREATED $(White)"

%.o : %.cpp
		@mkdir -p $(@D)
		$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	@make clean -C ./libft
	@make clean -C ./minilibx-linux
	@echo "$(Red)Cleaning object files...$(White)"
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "$(Red)$(NAME) DELETED $(White)"

re : fclean all

-include $(DEP)

.PHONY: re clean fclean