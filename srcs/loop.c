#include "pong.h"

bool	Process_Input(t_objects *objs)
{
	SDL_Event	e;

	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
		return (false);
	else if (e.key.keysym.sym == SDLK_ESCAPE)
		return (false);
	if (e.type == SDL_KEYDOWN)
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
	else if (e.type == SDL_KEYUP)
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
	return (true);
}

void	Update(t_objects *objs)
{
	float delta_time = (SDL_GetTicks() - objs->phys.last_t) / 1000.0f;
	objs->phys.last_t = SDL_GetTicks();

	objs->P1.y += delta_time * objs->phys.P1_v;
	objs->P2.y += delta_time * objs->phys.P2_v;
	objs->ball.y += delta_time * objs->phys.ball_vy;
	objs->ball.x += delta_time * objs->phys.ball_vx;

	if (objs->ball.y <= 0)
	{
		objs->phys.ball_vy = -objs->phys.ball_vy;

	}
	else if (objs->ball.y + objs->ball.h >= WINDOW_HEIGHT)
		objs->phys.ball_vy = -objs->phys.ball_vy;

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
