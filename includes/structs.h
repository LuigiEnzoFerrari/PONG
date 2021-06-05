#ifndef STRUCTS_H
# define STRUCTS_H

# include <SDL2/SDL.h>

typedef struct s_phisycs
{
	float	P1_v;
	float	P2_v;
	float	ball_vx;
	float	ball_vy;
	float	last_t;
	float	delta_time;
	float	random;
}	t_phisycs;

typedef struct s_objects
{
	SDL_FRect	P1;
	SDL_FRect	P2;
	SDL_FRect	ball;
	t_phisycs	phys;
}	t_objects;

#endif