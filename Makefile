NAME		= fractol

SRC 		= main.c setup.c event.c draw.c mandelbrot.c
HEADER 		= fractol.h

SRC_FOLDER	=	srcs
BIN_FOLDER	=	bin
OBJ_FOLDER	=	$(BIN_FOLDER)/obj

OBJ 		= $(addprefix $(OBJ_FOLDER)/,$(SRC:.c=.o))
SRCLOCA		= $(shell find $(SRC_FOLDER) -type d)
OBJLOCA		= $(subst $(SRC_FOLDER), $(OBJ_FOLDER), $(SRCLOCA))

YELLOW 		= \033[0;33m
GREEN		= \033[0;32m
END_COLOR	= \033[0m

LIBFT		=	libft/libft.a
LIB 		= 	libft
FLAGS		=	-Wall -Wextra -Werror

MINILIBX		:=	libmlx.a
MINILIBX_PATH :=  minilibx-macos
MINILIBX_LINK :=  -L $(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit
MINILIBX_INC  := -I $(MINILIBX_PATH)-I/usr/local/include

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX_PATH)/$(MINILIBX)
		@gcc -o $(NAME) $(LIBFT) $(OBJ) $(MINILIBX_LINK)
		@printf "$(GREEN)\\nCompilation FRACTOL finish \\n$(END_COLOR)"

$(OBJ_FOLDER)/%.o:	$(SRC_FOLDER)/%.c | $(OBJ_FOLDER)
	@gcc $< -c -o $@ $(FLAGS) -g

$(LIBFT):
	@make -C $(LIB) --no-print-directory

$(OBJ_FOLDER):
	@mkdir -p $(OBJLOCA)

$(BIN_FOLDER):
	@ mkdir -p $(BIN_FOLDER)

$(MINILIBX_PATH)/$(MINILIBX):
	@make -C $(MINILIBX_PATH)

clean :
	@make clean -C libft
	@make -C $(MINILIBX_PATH) clean
	@rm -rf $(BIN_FOLDER)
	@printf "$(GREEN)Clean [OK] $(END_COLOR)\n"

fclean : clean 
	@make fclean -C libft
	@make -C $(MINILIBX_PATH) clean
	@rm -rf $(NAME)
	@printf "$(GREEN)Fclean [OK] $(END_COLOR)\n"

re : fclean all

.PHONY : all clean fclean re
