NAME = game
SRCS = srcs
INC = includes
FILES = srcs/collisions.c srcs/initialization.c \
		srcs/input.c srcs/update.c srcs/render.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

build: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) main.c $(FILES) -o game -I $(INC) -lSDL2

run:
	./game

clean:
	@$(RM) game

re: clean build

.PHONY: build run clean re
