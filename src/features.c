/*
** features.c for wolf3d in /home/mael/wolf3d/src
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Jan 11 11:54:17 2017 mael drapier
** Last update Sun Jan 15 00:31:46 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include "wolf3d.h"

void	collision(t_player *player, t_map *map)
{
  int	x;
  int	y;

  x = (int) player->pos.x;
  y = (int) player->pos.y;
  if (map->tab[y][x] != 0)
    player->pos = player->old_pos;
}

void		draw_flash(t_my_framebuffer *framebuffer, t_player *player)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 20 + (int) player->battery * 2;
  to.x = 220;
  from.y = 60;
  to.y = 60;
  while (from.y < 70)
    {
      my_draw_line(framebuffer, from, to, COLOR_BACK);
      from.y = from.y + 1;
      to.y = to.y + 1;
    }
  from.x = 140;
  to.x = 170;
  from.y = 29;
  to.y = 20;
  if (player->flash != 0)
    {
      while (to.y <= 40)
	{
	  my_draw_line(framebuffer, from, to, sfWhite);
	  to.y = to.y + 1;
	}
    }
}

void		draw_flashlight(t_my_framebuffer *framebuffer, t_player *player)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 120;
  to.x = 130;
  from.y = 20;
  to.y = 20;
  while (from.y < 40)
    {
      my_draw_line(framebuffer, from, to, sfYellow);
      from.y = from.y + 1;
      to.y = to.y + 1;
    }
  to.x = 80;
  from.y = 25;
  to.y = 25;
  while (from.y < 35)
    {
      my_draw_line(framebuffer, from, to, sfYellow);
      from.y = from.y + 1;
      to.y = to.y + 1;
    }
  draw_flash(framebuffer, player);
}

void		use_flashlight(t_my_framebuffer *framebuffer, t_player *player)
{
  sfVector2i	from;
  sfVector2i	to;
  sfColor	color;

  color = sfYellow;
  if (player->flash != 0 && player->night_mode == 1)
    {
      player->battery = player->battery - 0.2;
      color = sfRed;
    }
  from.y = 60;
  to.y = 60;
  from.x = 20;
  to.x = 20 + (int) player->battery * 2;
  if (player->night_mode == 1)
    {
      draw_flashlight(framebuffer, player);
      while (from.y < 70)
	{
	  my_draw_line(framebuffer, from, to, color);
	  from.y = from.y + 1;
	  to.y = to.y + 1;
	}
    }
}

void		draw_night(t_my_framebuffer *framebuffer, float distance,
			  int x, t_player *player)
{
  sfVector2i	from;
  sfVector2i	to;
  sfVector2i	tmp;

  player->color.a = 255 - (80 - player->flash * 15) * distance;
  if (distance > 3 + player->flash)
    player->color.a = 0;
  distance = (float) HEIGHT / distance;
  from.x = x;
  from.y = HEIGHT / 2 - distance / 2;
  to.x = x;
  to.y = HEIGHT / 2 + distance / 2;
  my_draw_line(framebuffer, from, to, player->color);
  player->color = COLOR_WALL_1;
  tmp = from;
  from.y = to.y;
  to.y = HEIGHT;
  player->color.a = 7 + player->flash * 5;
  my_draw_line(framebuffer, from, to, player->color);
  from = tmp;
  to.y = 0;
  my_draw_line(framebuffer, from, to, sfBlack);
}
