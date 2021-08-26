#essential
NAME = game
CC = clang

#flags
CFLAGS = -Wall -Wextra -Werror
SDLFLAGS = `pkg-config --libs --cflags sdl2`
SANIT = -g -fsanitize=address

#includes
INC = includes
HEADERS = $(wildcard $(INC)/*.h)

#sources
SRCS_PATH = srcs
SRCS_NAME = collisions.c initialization.c \
		input.c update.c render.c
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

build: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SDLFLAGS) main.c $(SRCS) -o $@ -I $(INC) 

run: $(NAME)
	./game

clean:
	@$(RM) game

fclean: clean

re: clean build

.PHONY: build run clean re
