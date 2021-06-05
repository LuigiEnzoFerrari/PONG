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

bool	Process_Input(t_objects *objs)
{
	SDL_Event	e;

	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
		return (false);
	else if (e.key.keysym.sym == SDLK_ESCAPE)
		return (false);
	if (e.type == SDL_KEYDOWN)
		players_KeyDown(objs, e);
	else if (e.type == SDL_KEYUP)
		players_KeyRelease(objs, e);
	return (true);
}

void	Update(t_objects *objs)
{
	objs->phys.delta_time = (SDL_GetTicks() - objs->phys.last_t) / 1000.0f;
	objs->phys.last_t = SDL_GetTicks();
	objs->P1.y += objs->phys.delta_time * objs->phys.P1_v;
	objs->P2.y += objs->phys.delta_time * objs->phys.P2_v;
	objs->ball.y += objs->phys.delta_time * objs->phys.ball_vy
		* objs->phys.random;
	objs->ball.x += objs->phys.delta_time * objs->phys.ball_vx
		* objs->phys.random;
	collisions(objs);
	if (objs->ball.x <= 0 || objs->ball.x + objs->ball.w >= WINDOW_WIDTH)
	{
		objs->ball.x = (WINDOW_WIDTH / 2) - (objs->ball.w / 2);
		objs->ball.y = (WINDOW_HEIGHT / 2) - (objs->ball.h / 2);
		objs->phys.ball_vx = -objs->phys.ball_vx;
	}
}

void	Render(SDL_Renderer *renderer, t_objects *objs)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRectF(renderer, &objs->P2);
	SDL_RenderFillRectF(renderer, &objs->P1);
	SDL_RenderFillRectF(renderer, &objs->ball);
	SDL_RenderPresent(renderer);
}
