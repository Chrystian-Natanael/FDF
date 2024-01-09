#! ******************************************************************************#
#                                   NAME                                         #
#! ******************************************************************************#

NAME := fdf
.DEFAULT_GOAL := all
.PHONY: all clean fclean re libmlx
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

SRCS_PATH = ./src
INCS_PATH = ./src ./lib/libft ./lib/MLX42/include
BUILD_DIR := ./build/
LIBMLX	:= ./lib/MLX42
LIBFT_DIR := ./lib/libft/
MLX42_BUILD_DIR := ./lib/MLX42/build/

#! ******************************************************************************#
#                             COMMANDS AND FLAGS                                 #
#! ******************************************************************************#

MKDIR := mkdir -p
RM := rm -rf
SLEEP = sleep 0.1

CFLAGS = -Wall -Wextra -Werror
CC = cc
DFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LDLIBS = -lft -lmlx42 -ldl -lglfw -pthread -lm
LDFLAGS = $(addprefix -L,$(dir $(LIBS)))
OPTFLAGS = -Ofast
CPPFLAGS = $(addprefix -I,$(INCS_PATH)) -MMD -MP
COMP_OBJ = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE = $(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

#! ******************************************************************************#
#                                   DEFINE                                       #
#! ******************************************************************************#

ifdef WITH_DEBUG
	CFLAGS = $(DFLAGS)
endif

ifdef BONUS
	SRCS = SRCS_BONUS
endif

#! ******************************************************************************#
#                                   FILES                                        #
#! ******************************************************************************#

SRCS = main.c
SRCS_BONUS = 
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MLX42 = $(addprefix $(MLX42_BUILD_DIR), libmlx42.a)
LIBS := ./lib/libft/libft.a \
	./lib/MLX42/build/libmlx42.a
DEPS = $(OBJS:.o=.d)
OBJS += $(SRCS:%.c=$(BUILD_DIR)%.o)

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
	printf "[%3d%%] $(YELLOW) teste $(basename $(notdir $@)) \r$(RESET)\n" $$(echo $$(($(COUNT) * 100 / $(words $(OBJS)))))
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
	printf "$(GREEN)$(NAME) executable built\n$(RESET)"
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

fclean: clean

re: fclean all

-include $(DEPS)
