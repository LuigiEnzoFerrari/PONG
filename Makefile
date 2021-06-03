NAME = game

build: $(NAME)

$(NAME):
	gcc -Wall -std=c99 main.c -o game -lSDL2

run:
	./game

clean:
	rm -f game

re: clean
	rm -rf game