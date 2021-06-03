NAME = game
SRCS = srcs
INC = includes
FILES = loop.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

build: $(NAME)

$(NAME):
	gcc $(CFLAGS) main.c $(SRCS)/$(FILES) -o game -I $(INC) -lSDL2

run:
	./game

clean:
	rm -f game

re: clean build

.PHONY: build run clean re