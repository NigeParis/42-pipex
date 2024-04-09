###############################################################################
## ARGUMENTS

NAME=get_next_line_bonus.a
EXEC=outbonus
CFLAGS=-Wall -Wextra -Werror
SRCS=$(addprefix $(SRC_DIR), $(SRC))
OBJ=$(SRC:.c=.o)
HEAD=$(addprefix $(INCLUDE), $(HEADER))
CCOPTIONS=-c -g3 -D BUFFER_SIZE=42
SRC_OBJ=$(addprefix $(OBJ_DIR), $(OBJ))
##MAIN_SRC=$(addprefix $(SRC_DIR), $(MAIN))
##MAIN_OBJ=$(addprefix $(OBJ_DIR), $(MAIN:.c=.o))
CC=cc
############################################:###################################
## SOURCES 

SRC_DIR=
OBJ_DIR=
INCLUDE=
SRC=get_next_line_bonus.c get_next_line_utils_bonus.c



HEADER=get_next_line_bonus.h
###############################################################################
## RULES

all: $(NAME)
	@echo "\nDone ! .......\n"

$(NAME): $(OBJ)
	@echo "\nCreating Libft.a FILE .......\n"
	ar -rcs $(NAME) $(OBJ)
	@echo "\nlinking FILES .......\n"
##	cc $(OBJ) $(MAIN_OBJ) -o $(EXEC)

$(OBJ):
	@echo "\nCOMPILE all c files to .o FILES .......\n"
	$(CC) $(CFLAGS) $(CCOPTIONS) $(SRCS) -I.$(HEAD)
##	$(CC) $(CFLAGS) $(CCOPTIONS) $(MAIN_SRC) -o $(MAIN_OBJ)

clean:
	rm -f $(SRC_OBJ) $(MAIN_OBJ)

fclean:clean
	@echo "\nFCLEAN all .o et .a files .......\n"
	rm -f $(NAME) $(EXEC)

re:fclean all
	@echo "\nAll erased and re-compiled .......\n"

.PHONY: all clean fclean re
