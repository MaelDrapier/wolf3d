/*
** my_draw_line.c for wolf3d in /home/mael.drapier/wolf3d
** 
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
** 
** Started on  Mon Dec  5 14:59:30 2016 mael drapier
** Last update Sat Dec 24 13:20:20 2016 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include "wolf3d.h"

void	swap_values(sfVector2f *from, sfVector2f *to)
{
  float	temp;

  temp = from->x;
  from->x = to->x;
  to->x = temp;
  temp = from->y;
  from->y = to->y;
  to->y = temp;
}

void	vline(t_my_framebuffer *framebuffer, sfVector2f ffrom,
	      sfVector2f fto, sfColor color)
{
  if (ffrom.y > fto.y)
    swap_values(&ffrom, &fto);
  while (ffrom.y < fto.y)
    {
      my_put_pixel(framebuffer, ffrom.x, ffrom.y, color);
      ffrom.y = ffrom.y + 1;
    }
}

void	put_in_float(sfVector2f *ffrom, sfVector2f *fto,
		     sfVector2i *from, sfVector2i *to)
{
  ffrom->x = from->x;
  ffrom->y = from->y;
  fto->x = to->x;
  fto->y = to->y;
}

float	need_space(sfVector2f *ffrom, sfVector2f *fto, float slope)
{
  float	origin_y;

  origin_y = ffrom->y - (slope * ffrom->x);
  if (ffrom->x > fto->x)
    swap_values(ffrom, fto);
  return (origin_y);
}

void		my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
			     sfVector2i to, sfColor color)
{
  float		slope;
  float		origin_y;
  sfVector2f	ffrom;
  sfVector2f	fto;

  put_in_float(&ffrom, &fto, &from, &to);
  if (ffrom.x == fto.x)
    vline(framebuffer, ffrom, fto, color);
  else
    {
      slope = (ffrom.y - fto.y) / (ffrom.x - fto.x);
      origin_y = need_space(&ffrom, &fto, slope);
      while (ffrom.x != fto.x)
	{
	  my_put_pixel(framebuffer, ffrom.x, ffrom.y, color);
	  while (ffrom.y > (slope * ffrom.x + origin_y))
	    {
	      ffrom.y = ffrom.y - 0.25;
	      my_put_pixel(framebuffer, ffrom.x, ffrom.y, color);
	    }
	  ffrom.y = slope * ffrom.x + origin_y;
	  ffrom.x = ffrom.x + 0.25;
	}
      my_put_pixel(framebuffer, ffrom.x, ffrom.y, color);
    }
}
