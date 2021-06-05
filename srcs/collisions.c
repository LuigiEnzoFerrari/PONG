#include "pong.h"

static void	ball_walls_Collision(t_objects *objs)
{
	if (objs->ball.y <= 0)
	{
		objs->phys.ball_vy = -objs->phys.ball_vy;
		objs->ball.y = 0;
	}
	else if (objs->ball.y + objs->ball.h >= WINDOW_HEIGHT)
	{
		objs->phys.ball_vy = -objs->phys.ball_vy;
		objs->ball.y = WINDOW_HEIGHT - objs->ball.h;
	}
}

static float	RandomFloat(float a, float b)
{
	float	random;
	float	diff;

	random = ((float)rand()) / (float) RAND_MAX;
	diff = b - a;
	b = random * diff;
	return (a + b);
}

static void	ball_players_Collision(t_objects *objs)
{
	if (objs->ball.x + objs->ball.w >= objs->P2.x
		&& objs->ball.x +objs->ball.w <= objs->P2.x +objs->P2.w
		&& objs->ball.y + objs->ball.h >= objs->P2.y
		&& objs->ball.y <= objs->P2.y + objs->P2.h)
	{
		objs->phys.ball_vx = -objs->phys.ball_vx;
		objs->ball.x = objs->P2.x - objs->ball.w;
		objs->phys.random = 1.9;
	}
	else if (objs->ball.x <= objs->P1.x + objs->P1.w
		&& objs->ball.x >= objs->P1.x
		&& objs->ball.y + objs->ball.h >= objs->P1.y
		&& objs->ball.y <= objs->P1.y + objs->P1.h)
	{
		objs->phys.ball_vx = -objs->phys.ball_vx;
		objs->ball.x = objs->P1.x + objs->P1.w;
		objs->phys.random = RandomFloat(1, 2.5);
	}
}

static void	players_wall_Collision(t_objects *objs)
{
	if (objs->P1.y <= 0)
	{
		objs->phys.P1_v = 0;
		objs->P1.y = 0;
	}
	else if (objs->P1.y + objs->P1.h >= WINDOW_HEIGHT)
	{
		objs->phys.P1_v = 0;
		objs->P1.y = WINDOW_HEIGHT - objs->P1.h;
	}
	if (objs->P2.y <= 0)
	{
		objs->phys.P2_v = 0;
		objs->P2.y = 0;
	}
	else if (objs->P2.y + objs->P2.h >= WINDOW_HEIGHT)
	{
		objs->phys.P2_v = 0;
		objs->P2.y = WINDOW_HEIGHT - objs->P2.h;
	}
}

void	collisions(t_objects *objs)
{
	players_wall_Collision(objs);
	ball_walls_Collision(objs);
	ball_players_Collision(objs);
}
