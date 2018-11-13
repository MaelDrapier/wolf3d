/*
** window.c for wolf3d in /home/mael.drapier/wolf3d
**
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
**
** Started on  Sat Dec 24 13:57:49 2016 mael drapier
** Last update Tue Jan 17 20:31:20 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "wolf3d.h"

void	event_loop(t_player *player)
{
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    player->direction = player->direction + (float) FOV / 30;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    player->direction = player->direction - (float) FOV / 30;
  if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
    player->pos = move_forward(player->pos, player->direction, 0.08);
  if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
    player->pos = move_forward(player->pos, player->direction - 180, 0.08);
  if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
    player->pos = move_forward(player->pos, player->direction - 90, 0.05);
  if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
    player->pos = move_forward(player->pos, player->direction + 90, 0.05);
  if ((sfKeyboard_isKeyPressed(sfKeyN) == sfTrue) && player->night_mode == 0)
    player->night_mode = 1;
  if ((sfKeyboard_isKeyPressed(sfKeyB) == sfTrue) && player->night_mode == 1)
    player->night_mode = 0;
  if ((sfKeyboard_isKeyPressed(sfKeyF) == sfTrue) && player->flash == 0)
    if (player->battery > 0)
      player->flash = 2;
}

void	core_loop_bis(t_display *display, t_my_framebuffer *framebuffer,
		      t_map *map, t_player *player)
{
  if (player->win != 0)
    sfRenderWindow_close(display->window);
  player->old_pos = player->pos;
  event_loop(player);
  collision(player, map);
  sfRenderWindow_clear(display->window, sfBlack);
  call_rays(framebuffer, map, player);
  use_flashlight(framebuffer, player);
  draw_time(framebuffer, player);
  refill_battery(player, map);
  refill_wall(player, map);
}

void	core_loop(t_display *display, t_my_framebuffer *framebuffer,
		  t_map *map, t_player *player)
{
  while (sfRenderWindow_isOpen(display->window))
    {
      exit_map(player, map);
      while (sfRenderWindow_pollEvent(display->window, &display->event))
	{
	  if (display->event.type == sfEvtClosed)
	    sfRenderWindow_close(display->window);
	  if (display->event.key.code == sfKeyEscape)
	    sfRenderWindow_close(display->window);
	  if (display->event.key.code == sfKeyF)
	    player->flash = 0;
	}
      core_loop_bis(display, framebuffer, map, player);
      sfTexture_updateFromPixels(display->texture, framebuffer->pixels,
				 WIDTH, HEIGHT, 0, 0);
      sfRenderWindow_drawSprite(display->window, display->sprite, NULL);
      sfRenderWindow_display(display->window);
    }
}

int		core(t_display *display, t_my_framebuffer *framebuffer,
		     t_map *map)
{
  t_player	player;

  player.pos.x = START_X;
  player.pos.y = START_Y;
  player.night_mode = DEFAULT_NIGHT;
  player.direction = 0;
  player.flash = 0;
  player.battery = 100;
  player.time = 100;
  player.win = 0;
  display->window = create_win("Wolf3d", WIDTH, HEIGHT);
  display->sprite = sfSprite_create();
  display->texture = sfTexture_create(WIDTH, HEIGHT);
  sfSprite_setTexture(display->sprite, display->texture, sfTrue);
  core_loop(display, framebuffer, map, &player);
  return (0);
}

int			main(int ac, char **av)
{
  t_display		display;
  t_my_framebuffer	framebuffer;
  t_map			map;

  if (ac != 2)
    {
      error_arg();
      return (RETURN_FAIL);
    }
  if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
    {
      show_helper();
      return (RETURN_SUCCESS);
    }
  if (open_map(&map, av[1]) == RETURN_FAIL)
    {
      error_map(av[1]);
      return (RETURN_FAIL);
    }
  framebuffer = my_framebuffer_create(WIDTH, HEIGHT);
  core(&display, &framebuffer, &map);
  free_this(&display, &framebuffer);
  return (RETURN_SUCCESS);
}
