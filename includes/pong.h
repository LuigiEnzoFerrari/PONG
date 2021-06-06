#ifndef PONG_H
# define PONG_H

# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdbool.h>
# include <time.h>
# include <math.h>
# include "structs.h"

# define WINDOW_HEIGHT	576
# define WINDOW_WIDTH	720

void	Process_Input(t_objects *objs);
void	Update(t_objects *objs);
void	Render(SDL_Renderer *renderer, t_objects *objs);
int		Init_All(SDL_Window **window, SDL_Renderer **renderer);
void	collisions(t_objects *objs);
void	Setup(t_objects *objs);

#endif