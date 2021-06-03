#ifndef PONG_H
# define PONG_H

# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdbool.h>
# include "structs.h"

# define WINDOW_HEIGHT	414
# define WINDOW_WIDTH	736

bool	Process_Input(t_objects *objs);
void	Update(t_objects *objs);
void	Render(SDL_Renderer *renderer, t_objects *objs);

#endif