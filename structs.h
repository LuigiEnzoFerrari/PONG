#ifndef STRUCTS_H
# define STRUCTS_H

# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>

# define WINDOW_HEIGHT	414
# define WINDOW_WIDTH	736

typedef struct s_phisycs
{
	float	P1_v;
	float	P2_v;
	float	ball_v;
}	t_phisycs;

typedef struct s_objects
{
	SDL_FRect	P1;
	SDL_FRect	P2;
	SDL_FRect	ball;
	t_phisycs	phys;
}	t_objects;

#endif