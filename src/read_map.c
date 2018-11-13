/*
** read_map.c for wolf3d in /home/mael.drapier/wolf3d
**
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
**
** Started on  Sat Dec 24 14:54:21 2016 mael drapier
** Last update Wed Dec 20 23:31:53 2017 mael drapier
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "wolf3d.h"

int	nb_columns(char *buf)
{
  int	i;

  i = 0;
  while (buf[i] != '\n')
    {
      i = i + 1;
    }
  return (i);
}

int	nb_lines(char *buf)
{
  int	res;
  int	i;

  res = 0;
  i = 0;
  while (buf[i] != '\0')
    {
      if (buf[i] == '\n')
	res = res + 1;
      i = i + 1;
    }
  return (res);
}

int	put_in_tab(t_map *map, char *buf, int x, int y)
{
  int	z;

  z = 0;
  if ((map->tab = malloc(sizeof(int*) * (map->height + 1))) == NULL)
    return (RETURN_FAIL);
  if ((map->tab[0] = malloc(sizeof(int) * map->width)) == NULL)
    return (RETURN_FAIL);
  while (y < map->height)
    {
      if (buf[x] == '\n')
	{
	  y = y + 1;
	  if ((map->tab[y] = malloc(sizeof(int) * map->width)) == NULL)
	    return (RETURN_FAIL);
	  x = x + 1;
	  z = 0;
	}
      map->tab[y][z] = buf[x] - 48;
      x = x + 1;
      z = z + 1;
    }
  return (RETURN_SUCCESS);
}

int	open_map(t_map *map, char *name)
{
  int	fd;
  char	*buf;

  map->width = 4;
  fd = open(name, O_RDONLY);
  if (fd == -1)
    return (RETURN_FAIL);
  if ((buf = malloc(sizeof(char) * 4096)) == NULL)
    return (RETURN_FAIL);
  if (read(fd, buf, 4095) <= 0)
    return (RETURN_FAIL);
  close (fd);
  buf[4095] = '\0';
  map->width = nb_columns(buf);
  map->height = nb_lines(buf);
  put_in_tab(map, buf, 0, 0);
  free(buf);
  return (RETURN_SUCCESS);
}
