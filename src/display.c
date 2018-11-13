/*
** display.c for wold3d in /home/mael.drapier/wolf3d
** 
** Made by mael drapier
** Login   <mael.drapier@epitech.net>
** 
** Started on  Sat Dec 24 13:42:28 2016 mael drapier
** Last update Sat Dec 24 13:49:03 2016 mael drapier
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i = i + 1;
    }
  return (i);
}

void	my_putstr(int fd, char *str)
{
  write(fd, str, my_strlen(str));
}
