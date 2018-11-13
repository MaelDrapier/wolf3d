/*
** drawing.c for wolf3d in /home/mael/wolf3d/src
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Mon Jan  9 13:58:50 2017 mael drapier
** Last update Mon Jan 23 18:02:42 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <math.h>
#include "wolf3d.h"

int		draw_rays(t_my_framebuffer *framebuffer, float distance,
			  int x, sfColor color)
{
  sfVector2i	from;
  sfVector2i	to;
  sfVector2i	tmp;

  distance = (float) HEIGHT / distance;
  from.x = x;
  from.y = HEIGHT / 2 - distance / 2;
  to.x = x;
  to.y = HEIGHT / 2 + distance / 2;
  my_draw_line(framebuffer, from, to, color);
  tmp = from;
  from.y = to.y;
  to.y = HEIGHT;
  my_draw_line(framebuffer, from, to, COLOR_GROUND);
  from = tmp;
  to.y = 0;
  my_draw_line(framebuffer, from, to, COLOR_SKY);
  return (0);
}

sfColor		set_color_special(t_player *player, t_map *map,
				  float dir, float distance)
{
  sfVector2f	pos_in;
  int		x;
  int		y;

  pos_in = move_forward(player->pos, dir, distance + MOVE_BACK);
  x = (int) pos_in.x;
  y = (int) pos_in.y;
  if (map->tab[y][x] == 2)
    return (COLOR_EXIT);
  if (map->tab[y][x] == 3)
    return (COLOR_WALL_BATTERY);
  if (map->tab[y][x] == 4)
    return (COLOR_WALL_TIME);
  return (player->color);
}

sfColor		set_color(t_player *player, float dir, float distance)
{
  sfVector2f	pos_in;
  sfVector2f	pos_out;
  sfVector2i	delta_pos;

  pos_in = move_forward(player->pos, dir, distance + MOVE_BACK);
  pos_out = move_forward(player->pos, dir, distance);
  delta_pos.x =  (int) pos_out.x - pos_in.x;
  delta_pos.y =  (int) pos_out.y - pos_in.y;
  if (player->night_mode == 0)
    {
      if (delta_pos.y < 0)
	return (COLOR_WALL_2);
      if (delta_pos.x < 0)
	return (COLOR_WALL_3);
    }
  return (COLOR_WALL_1);
}

void	call_mode(t_player *player, t_my_framebuffer *framebuffer,
		  float distance, int x)
{
  if (player->night_mode == 0)
    draw_rays(framebuffer, distance, x, player->color);
  else
    draw_night(framebuffer, distance, x, player);
}

void		call_rays(t_my_framebuffer *framebuffer, t_map *map,
			  t_player *player)
{
  int		x;
  float		increment;
  float		distance;
  float		dir;
  sfVector2i	mapSize;

  x = 0;
  mapSize.x = map->width;
  mapSize.y = map->height;
  increment = (float) FOV / WIDTH;
  dir = player->direction - FOV / 2;
  while (x < WIDTH)
    {
      distance = raycast(player->pos, dir, map->tab, mapSize);
      player->color = set_color(player, dir, distance);
      player->color = set_color_special(player, map, dir, distance);
      if (FOV < 150)
	distance = distance * cos((dir - player->direction) * M_PI / 180);
      call_mode(player, framebuffer, distance, x);
      dir = dir + increment;
      x = x + 1;
    }
}
