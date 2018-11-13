/*
** raycast.c for wolf3d in /home/mael.drapier/wolf3d/src
**
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
**
** Started on  Sat Dec 24 13:28:00 2016 mael drapier
** Last update Tue Jan 24 14:14:03 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include "wolf3d.h"

float		polisher(sfVector2f pos, float direction,
			 float distance, int **map)
{
  sfVector2f	new_pos;
  int		x;
  int		y;

  new_pos = move_forward(pos, direction, distance);
  x = (int) new_pos.x;
  y = (int) new_pos.y;
  if (x < 0 || y < 0)
    return (distance);
  while (map[y][x] != 0)
    {
      distance = distance - MOVE_BACK;
      new_pos = move_forward(pos, direction, distance);
      x = (int) new_pos.x;
      y = (int) new_pos.y;
      if (x < 0 || y < 0)
	return (distance);
    }
  return (distance);
}

float		raycast(sfVector2f pos, float direction,
			int **map, sfVector2i mapSize)
{
  float		distance;
  sfVector2f	new_pos;
  int		x;
  int		y;

  distance = MOVE;
  new_pos = move_forward(pos, direction, distance);
  x = (int) new_pos.x;
  y = (int) new_pos.y;
  if (x < 0 || x >= mapSize.x || y < 0 || y >= mapSize.y)
    return (distance);
  while (map[y][x] == 0)
    {
      distance = distance + MOVE;
      new_pos = move_forward(pos, direction, distance);
      x = (int) new_pos.x;
      y = (int) new_pos.y;
      if (x < 0 || x >= mapSize.x || y < 0 || y >= mapSize.y)
        return (distance);
    }
  distance = polisher(pos, direction, distance, map);
  return (distance);
}
