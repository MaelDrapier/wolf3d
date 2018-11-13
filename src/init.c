/*
** init.c for wolf3d in /home/mael/wolf3d/src
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Fri Jan  6 13:07:04 2017 mael drapier
** Last update Fri Jan  6 13:13:35 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include "wolf3d.h"

sfRenderWindow		*create_win(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (0);
  return (window);
}

t_my_framebuffer	my_framebuffer_create(int wdt, int hgt)
{
  t_my_framebuffer	framebuffer;
  int			i;

  i = 0;
  framebuffer.width = wdt;
  framebuffer.height = hgt;
  framebuffer.pixels = malloc(wdt * hgt * 4 * sizeof(framebuffer.pixels));
  while (i < wdt * hgt * 4)
    {
      framebuffer.pixels[i] = 0;
      i = i + 1;
    }
  return (framebuffer);
}
