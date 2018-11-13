/*
** features2.c for wolf3d in /home/mael/wolf3d
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Fri Jan 13 14:45:33 2017 mael drapier
** Last update Sun Jan 15 00:32:03 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "wolf3d.h"

void		exit_map(t_player *player, t_map *map)
{
  int		x;
  int		y;
  sfVector2f	tmp_pos;

  tmp_pos = move_forward(player->pos, player->direction, 0.8);
  x = (int) tmp_pos.x;
  y = (int) tmp_pos.y;
  if (map->tab[y][x] == 2)
    player->win = 1;
}

void	refill_battery(t_player *player, t_map *map)
{
  int		x;
  int		y;
  sfVector2f	tmp_pos;

  tmp_pos = move_forward(player->pos, player->direction, 0.8);
  x = (int) tmp_pos.x;
  y = (int) tmp_pos.y;
  if (map->tab[y][x] == 3)
    player->battery = 100;
}

void	refill_wall(t_player *player, t_map *map)
{
  int		x;
  int		y;
  sfVector2f	tmp_pos;

  tmp_pos = move_forward(player->pos, player->direction, 0.8);
  x = (int) tmp_pos.x;
  y = (int) tmp_pos.y;
  if (map->tab[y][x] == 4)
    player->time = 100;
}

void	draw_time(t_my_framebuffer *framebuffer, t_player *player)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 40;
  to.x = WIDTH - 40;
  from.y = HEIGHT - 80;
  to.y = HEIGHT - 80;
  while (from.y <= HEIGHT - 70)
    {
      my_draw_line(framebuffer, from, to, COLOR_BACK);
      from.y = from.y + 1;
      to.y = to.y + 1;
    }
  to.x = (int) 40 + (WIDTH - 80) * (player->time / 100);
  while (from.y > HEIGHT - 80)
    {
      from.y = from.y - 1;
      to.y = to.y - 1;
      my_draw_line(framebuffer, from, to, sfBlue);
    }
  player->time = player->time - TIME_SPEED;
  if (player->time < 0)
    player->win = -1;
}

void	free_this(t_display *display, t_my_framebuffer *framebuffer)
{
  free(framebuffer->pixels);
  sfTexture_destroy(display->texture);
  sfSprite_destroy(display->sprite);
  sfRenderWindow_destroy(display->window);
}
