/*
** move_forward.c for wolf3d in /home/mael.drapier/wolf3d/src
**
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
**
** Started on  Sat Dec 24 13:24:27 2016 mael drapier
** Last update Sun Jan 15 22:46:32 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <math.h>

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f	new_pos;
  float		dir;

  dir = direction * (M_PI / 180);
  new_pos.y = pos.y + distance * sin(dir);
  new_pos.x = pos.x + distance * cos(dir);
  return (new_pos);
}
