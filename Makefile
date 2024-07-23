#! ******************************************************************************#
#                                   NAME                                         #
#! ******************************************************************************#

NAME = fdf
.DEFAULT_GOAL := all
.PHONY: all clean fclean re
.SILENT:

#! ******************************************************************************#
#                                   COLORS                                       #
#! ******************************************************************************#

GREEN = \033[32m
YELLOW = \033[33m
PURPLE = \033[35m
RED = \033[31m
WHITE = \033[37m
RESET = \033[0m

#! ******************************************************************************#
#                                   PATH                                         #
#! ******************************************************************************#

SRCS_PATH = ./src/
INCS_PATH = ./src/ ./lib/libft/include/ ./lib/MLX42/include/
BUILD_DIR := ./build/
LIBMLX	:= ./lib/MLX42/
LIBFT_DIR := ./lib/libft/
MLX42_BUILD_DIR := ./lib/MLX42/build/

#! ******************************************************************************#
#                                   FILES                                        #
#! ******************************************************************************#

SRCS =	$(addprefix $(SRCS_PATH),\
		main.c \
		ft_parse_map.c \
		ft_assets.c \
		ft_utils.c \
		ft_draw_line.c \
		ft_projection.c \
		ft_commands.c \
		ft_menu.c \
		ft_xiaolin.c \
		functions.c \
		xiaolin_utils.c \
		ft_draw_line_utils.c)

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MLX42 = $(addprefix $(MLX42_BUILD_DIR), libmlx42.a)
LIBS := ./lib/libft/libft.a \
	./lib/MLX42/build/libmlx42.a
OBJS = $(SRCS:%.c=$(BUILD_DIR)%.o)
DEPS = $(OBJS:.o=.d)

#! ******************************************************************************#
#                                    COMMANDS                                    #
#! ******************************************************************************#

MKDIR := mkdir -p
RM := rm -rf
SLEEP = sleep 0.1
CC = cc

#! ******************************************************************************#
#                                 FLAGS E COMP                                   #
#! ******************************************************************************#

CFLAGS = -Wall -Wextra -Werror -g3
DFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LDLIBS = -lft -lmlx42 -ldl -lglfw -pthread -lm
LDFLAGS = $(addprefix -L,$(dir $(LIBS)))
CPPFLAGS = $(addprefix -I,$(INCS_PATH)) -MMD -MP
COMP_OBJ = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE = $(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

#! ******************************************************************************#
#                                  FUNCTIONS                                     #
#! ******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMP_OBJ)
	$(SLEEP)
	printf "Compiling FDF$(YELLOW) %d%%\r$(FCOLOR)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
endef

define comp_libft
	printf "$(YELLOW)Building libft files\n$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)
endef

define comp_libmlx
	printf "$(YELLOW)Building mlx42 files\n$(RESET)"
	git submodule update --init --recursive >/dev/null 2>&1 || true
	git submodule foreach --recursive git fetch >/dev/null 2>&1 || true
	sed -i 's/3\.18/3.16/g' $(LIBMLX)CMakeLists.txt >/dev/null 2>&1 || true
	cd $(LIBMLX) && cmake -B build -DDEBUG=1 >/dev/null 2>&1 || true
	cd $(LIBMLX) && cmake --build build -j4
endef

define comp_exe
	$(COMP_EXE)
	printf "\n"
	printf "$(GREEN)FDF ->$(RESET)$(PURPLE) READY\n$(RESET)"
endef

#! ******************************************************************************#
#                                   TARGETS                                      #
#! ******************************************************************************#

all: $(LIBFT) $(MLX42) $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_exe)

$(MLX42):
	$(call comp_libmlx)

$(LIBFT):
	$(call comp_libft)

clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(MLX42_BUILD_DIR)/libmlx42.a

re: fclean all

-include $(DEPS)
