#include "structs.h"

float	last_time;

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

int	Process_Input(t_objects *objs)
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

void	Setup(t_objects *objs)
{
	objs->P1.w = WINDOW_WIDTH / 24;
	objs->P1.h = WINDOW_HEIGHT / 4;
	objs->P1.x = (WINDOW_WIDTH / 12) - objs->P1.w;
	objs->P1.y = (WINDOW_HEIGHT / 2) - objs->P1.h / 2;
	objs->phys.P1_v = 0;

	objs->P2.w = WINDOW_WIDTH / 24;
	objs->P2.h = WINDOW_HEIGHT / 4;
	objs->P2.x = WINDOW_WIDTH - (WINDOW_WIDTH / 12);
	objs->P2.y = (WINDOW_HEIGHT / 2) - objs->P1.h / 2;
	objs->phys.P2_v = 0;

	objs->ball.w = objs->P1.w / 2;
	objs->ball.h = objs->P1.w / 2;
	objs->ball.x = objs->P1.w;
	objs->ball.y = objs->P1.w;
}

void	Update(t_objects *objs)
{
	float delta_time = (SDL_GetTicks() - last_time) / 1000.0f;
	last_time = SDL_GetTicks();

	objs->P1.y += delta_time * objs->phys.P1_v;
	objs->P2.y += delta_time * objs->phys.P2_v;
	objs->ball.y += delta_time * 50;
	objs->ball.x += delta_time * 50;
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

void	Destroy_All(SDL_Window **window, SDL_Renderer **renderer)
{
	SDL_DestroyRenderer(*renderer);
	SDL_DestroyWindow(*window);
	SDL_Quit();
}

int	main(void)
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_objects		objs;
	bool			game;

	last_time = 0;
	if (!Init_All(&window, &renderer))
		return (0);
	Setup(&objs);
	game = true;
	while (game)
	{
		game = Process_Input(&objs);
		Update(&objs);
		Render(renderer, &objs);
	}
	Destroy_All(&window, &renderer);
	return (0);
}
