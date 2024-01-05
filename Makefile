# ! --------------------------------------------------------------------------------------------------------------------------------
# ! NAME

NAME := fdf
.DEFAULT_GOAL :=
.PHONY: all clean fclean re libmlx
.SILENT:

# ! --------------------------------------------------------------------------------------------------------------------------------
# ! COLORS

GREEN = \033[32m
YELLOW = \033[33m
PURPLE = \033[35m
RED = \033[31m
WHITE = \033[37m
RESET = \033[0m

# ! --------------------------------------------------------------------------------------------------------------------------------
# ! PATH

SRCS_PATH = 
OBJS_PATH = 
INCS_PATH = 
UTILS_PATH = 
LIBMLX	:= ./lib/MLX42

# ! --------------------------------------------------------------------------------------------------------------------------------
# ! COMMANDS AND FLAGS

MKDIR := mkdir -p
CC = cc
RM := rm -rf
SLEEP = sleep 0.1
CFLAGS = -Wall -Wextra -Werror
OPTFLAGS = -Ofast -flto
DEBUGFLAGS = -g3 -fsanitize=address

# ! --------------------------------------------------------------------------------------------------------------------------------
# ! FILES

SRCS = 

OBJS = $(patsubst %, $(OBJS_PATH)/%, $(notdir $(SRCS:.c=.o)))

# ! --------------------------------------------------------------------------------------------------------------------------------
# ! RULES

all: 

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	
$(NAME): libmlx

clean:

fclean: clean

re: fclean all

