NAME = lem-in

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
HEADERS = $(addprefix, $(INC_PATH), $(HEADER_NAME))

FLAGS = -Wall -Werror -Wextra -O2

HEADER_NAME = lemin.h

SRC_NAME = bfs.c connect_1.c connect_2.c del_waste_input_links.c \
	del_waste_output_links.c launch_ant_1.c launch_ant_2.c lemin.c parser.c \
	parser_help.c parser_links.c parser_room.c print.c ways.c

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -lft -L $(LIB_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

.PHONY: all fclean clean re