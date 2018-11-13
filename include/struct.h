/*
** struct.h for wolf3d in /home/mael.drapier/wolf3d/include
**
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
**
** Started on  Sat Dec 24 13:21:21 2016 mael drapier
** Last update Sat Jan 14 23:07:23 2017 mael drapier
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <SFML/Graphics/RenderWindow.h>

typedef	struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef	struct		s_display
{
  sfRenderWindow	*window;
  sfEvent		event;
  sfSprite		*sprite;
  sfTexture		*texture;
}			t_display;

typedef	struct		s_map
{
  int			width;
  int			height;
  int			**tab;
}			t_map;

typedef	struct		s_player
{
  sfVector2f		pos;
  sfVector2f		old_pos;
  float			direction;
  sfColor		color;
  int			night_mode;
  int			win;
  float			time;
  int			flash;
  float			battery;
}			t_player;

#endif /* !STRUCT_H_ */
