#include "pong.h"

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

	srand(time(NULL));
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
