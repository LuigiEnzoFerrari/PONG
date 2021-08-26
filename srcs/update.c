#include "pong.h"

static void	restart(t_objects *objs)
{
	objs->P1.x = (WINDOW_WIDTH / 12) - objs->P1.w;
	objs->P1.y = (WINDOW_HEIGHT / 2) - objs->P1.h / 2;
	objs->P2.x = WINDOW_WIDTH - (WINDOW_WIDTH / 12);
	objs->P2.y = (WINDOW_HEIGHT / 2) - objs->P1.h / 2;
	objs->ball.x = (WINDOW_WIDTH / 2) - (objs->ball.w / 2);
	objs->ball.y = (WINDOW_HEIGHT / 2) - (objs->ball.h / 2);
	objs->phys.ball_vy = 275;
	objs->phys.ball_vx = 275;
	objs->phys.ball_vx = -objs->phys.ball_vx;
	objs->phys.random = 1;
	objs->gstat.frozen = true;
}

void	Update(t_objects *objs)
{
	objs->phys.delta_time = (SDL_GetTicks() - objs->phys.last_t) / 1000.0f;
	objs->phys.last_t = SDL_GetTicks();
	if (objs->gstat.frozen == false)
	{
		objs->P1.y += objs->phys.delta_time * objs->phys.P1_v;
		objs->P2.y += objs->phys.delta_time * objs->phys.P2_v;
		objs->ball.y += objs->phys.delta_time * objs->phys.ball_vy
			* objs->phys.random;
		objs->ball.x += objs->phys.delta_time * objs->phys.ball_vx
			* objs->phys.random;
	}
	collisions(objs);
	if (objs->ball.x <= 0 || objs->ball.x + objs->ball.w >= WINDOW_WIDTH)
		restart(objs);
}
