###############################################################################
## ARGUMENTS

NAME= pipex
CFLAGS=  ##-Wall -Wextra -Werror -g3

SRCS=$(addprefix $(SRC_DIR), $(SRC))
OBJ=$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
HEAD=$(addprefix $(INCLUDE), $(HEADER))

CC=cc

###############################################################################
## SOURCES 

SRC_DIR=
OBJ_DIR=

INCLUDE= -I./usr/include/
SRC= ./src/main.c ./src/get_path.c ./src/errors.c ./src/get_cmds.c

LIBFT= ./libft/libft.a
FT_PRINTF= ./ft_printf/libftprintf.a

HEADER=

###############################################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating FILE .......\n"
	@make -C ./libft/ all
	@make -C ./ft_printf/ all
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@echo "COMPILE all c files to .o FILES .......\n"
	@$(CC) $(CFLAGS) -c $(SRCS)  $(HEAD)

lib:
	@make -C ./libft/ re 
	@make -C ./ft_printf/ re

libclean:
	@make -C ./libft/ clean
	@make -C ./ft_printf/ clean

libfclean:
	@make -C ./libft/ fclean
	@make -C ./ft_printf/ fclean

clean: libclean
	@rm -f $(OBJ)

fclean:clean libfclean
	@echo "FCLEAN all .o et .a files .......\n"
	@rm -f $(NAME)

re: fclean libfclean lib all
	@echo "All erased and re-compiled .......\n"

.PHONY: all lib libclean clean fclean re bonus
