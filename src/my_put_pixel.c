/*
** my_put_pixel.c for wolf3d in /home/mael.drapier/wolf3d
** 
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
** 
** Started on  Mon Dec  5 14:58:23 2016 mael drapier
** Last update Sat Dec 24 13:20:51 2016 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include "wolf3d.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x,
		     int y, sfColor color)
{
  int	draw;

  draw = 1;
  if (x < 0 || x > framebuffer->width)
    draw = 0;
  if (y < 0 || y > framebuffer->height)
    draw = 0;
  if (draw == 1)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
