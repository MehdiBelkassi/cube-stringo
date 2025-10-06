SRC = parsing/file1.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c main.c \
	parsing/helpers.c parsing/read_map.c parsing/read_all.c

OBJ = $(SRC:.c=.o)
CC = cc -Wall -Wextra -Werror 
INCLUDES = cub3d.h get_next_line/get_next_line.h

NAME = cub3d

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
