#include "pong.h"

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
