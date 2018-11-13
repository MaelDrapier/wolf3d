/*
** wolf3d.h for wolf3d in /home/mael.drapier/wolf3d/include
**
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
**
** Started on  Sat Dec 24 13:16:28 2016 mael drapier
** Last update Tue Jan 24 15:14:17 2017 mael drapier
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

# define RETURN_SUCCESS 0
# define RETURN_FAIL 84
# define WIDTH 1600
# define HEIGHT 900
# define FOV 60
# define MOVE 0.02
# define MOVE_BACK 0.001
# define START_X 1.5
# define START_Y 1.5
# define DEFAULT_NIGHT 0
# define TIME_SPEED 0.01
# define COLOR_WALL_1 (sfColor) {150, 150, 150, 255}
# define COLOR_WALL_2 (sfColor) {125, 125, 125, 255}
# define COLOR_WALL_3 (sfColor) {100, 100, 100, 255}
# define COLOR_GROUND (sfColor) {50, 50, 50, 255}
# define COLOR_SKY (sfColor) {0, 200, 255, 255}
# define COLOR_BACK (sfColor) {80, 25, 25, 255}
# define COLOR_WALL_BATTERY (sfColor) {180, 150, 0, 255}
# define COLOR_WALL_TIME (sfColor) {0, 100, 200, 255}
# define COLOR_EXIT (sfColor) {0, 100, 0, 255}
# include "struct.h"

void			error_arg();
void			error_map(char *name);
void			show_helper();
void			my_put_pixel(t_my_framebuffer *framebuffer, int x,
				     int y, sfColor color);
void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from,
				     sfVector2i to, sfColor color);
void			my_putstr(int fd, char *str);
sfRenderWindow		*create_win(char *name, int width, int height);
t_my_framebuffer	my_framebuffer_create(int wdt, int hgt);
void			free_this(t_display *display,
				  t_my_framebuffer *framebuffer);
int			open_map(t_map *map, char *name);
sfVector2f		move_forward(sfVector2f pos, float direction,
				     float distance);
void			call_rays(t_my_framebuffer *framebuffer, t_map *map,
				  t_player *player);
float			raycast(sfVector2f pos, float direction,
			int **map, sfVector2i mapSize);
void			collision(t_player *player, t_map *map);
void			draw_night(t_my_framebuffer *framebuffer,
				   float distance,
				   int x, t_player *player);
void			use_flashlight(t_my_framebuffer *framebuffer,
				       t_player *player);
void			draw_time(t_my_framebuffer *framebuffer,
				  t_player *player);
void			refill_battery(t_player *player, t_map *map);
void			refill_wall(t_player *player, t_map *map);
void			exit_map(t_player *player, t_map *map);

#endif /* !WOLF3D_H_ */
