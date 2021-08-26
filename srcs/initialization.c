#include "pong.h"

int	Init_All(SDL_Window **window, SDL_Renderer **renderer)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Error initiazling SDL: %s.\n", SDL_GetError());
		return (0);
	}
	*window = SDL_CreateWindow("Pong",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT,
			0);
	if (!*window)
	{
		fprintf(stderr, "Window Creation Failed: %s\n", SDL_GetError());
		return (0);
	}
	*renderer = SDL_CreateRenderer(*window, -1, 0);
	if (!*renderer)
	{
		fprintf(stderr, "Window Rendering Failed: %s\n", SDL_GetError());
		return (0);
	}
	return (1);
}

void	Setup(t_objects *objs)
{
	objs->P1.w = WINDOW_WIDTH / 60;
	objs->P1.h = WINDOW_HEIGHT / 5;
	objs->P1.x = (WINDOW_WIDTH / 12) - objs->P1.w;
	objs->P1.y = (WINDOW_HEIGHT / 2) - objs->P1.h / 2;
	objs->phys.P1_v = 0;
	objs->P2.w = WINDOW_WIDTH / 60;
	objs->P2.h = objs->P1.h;
	objs->P2.x = WINDOW_WIDTH - (WINDOW_WIDTH / 12);
	objs->P2.y = (WINDOW_HEIGHT / 2) - objs->P1.h / 2;
	objs->phys.P2_v = 0;
	objs->ball.w = objs->P1.w;
	objs->ball.h = objs->P1.w;
	objs->ball.x = WINDOW_WIDTH / 2;
	objs->ball.y = WINDOW_HEIGHT / 2;
	objs->phys.ball_vy = 275;
	objs->phys.ball_vx = 275;
	objs->phys.last_t = 0;
	objs->phys.random = 1;
	objs->phys.delta_time = 0;
	objs->gstat.game = true;
	objs->gstat.frozen = true;
}
