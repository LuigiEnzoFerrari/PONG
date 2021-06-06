#include "pong.h"

static void	players_KeyDown(t_objects *objs, SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_UP)
		objs->phys.P1_v = -400;
	if (e.key.keysym.sym == SDLK_DOWN)
		objs->phys.P1_v = 400;
	if (e.key.keysym.sym == SDLK_w)
		objs->phys.P2_v = -400;
	if (e.key.keysym.sym == SDLK_s)
		objs->phys.P2_v = 400;
}

static void	players_KeyRelease(t_objects *objs, SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_UP)
		objs->phys.P1_v = 0;
	if (e.key.keysym.sym == SDLK_DOWN)
		objs->phys.P1_v = 0;
	if (e.key.keysym.sym == SDLK_w)
		objs->phys.P2_v = 0;
	if (e.key.keysym.sym == SDLK_s)
		objs->phys.P2_v = 0;
}

void	Process_Input(t_objects *objs)
{
	SDL_Event	e;

	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
		objs->gstat.game = false;
	else if (e.key.keysym.sym == SDLK_ESCAPE)
		objs->gstat.game = false;
	if (e.type == SDL_KEYDOWN)
		players_KeyDown(objs, e);
	else if (e.type == SDL_KEYUP)
	{
		players_KeyRelease(objs, e);
		if (e.key.keysym.sym == SDLK_SPACE && objs->gstat.frozen)
			objs->gstat.frozen = false;
		else if (e.key.keysym.sym == SDLK_SPACE && !objs->gstat.frozen)
			objs->gstat.frozen = true;
	}
}
