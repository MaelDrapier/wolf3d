/*
** helper.c for wolf3d in /home/mael/wolf3d/src
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Jan 10 15:16:30 2017 mael drapier
** Last update Sun Jan 15 22:46:24 2017 mael drapier
*/

#include "wolf3d.h"

void	error_arg()
{
  my_putstr(2, "ERROR: too few or too much arguments\n");
  my_putstr(2, "Try './wolf3d -h' for more informations.\n");
}

void	error_map(char *name)
{
  my_putstr(2, "ERROR: cannot open file '");
  my_putstr(2, name);
  my_putstr(2, "'\nTry './wolf3d -h' for more informations.\n");
}

void	show_helper()
{
  my_putstr(1, "USAGE\n\t\t./wolf3d map.txt\n");
  my_putstr(1, "DESCRIPTION\nmap.txt\t\tFile representing ");
  my_putstr(1, "the level for the wolf3d game,\n");
  my_putstr(1, "\t\tcontaining '0' for places where ");
  my_putstr(1, "you can move and '1' for walls;\n\t\t");
  my_putstr(1, "'2' represents the exit, '3' the places where you can");
  my_putstr(1, " refill\n\t\tyour battery, ");
  my_putstr(1, "and '4' the places where you can reset the timer.\n");
  my_putstr(1, "HOW TO PLAY\n\t\tYou can move with the 'ZQSD' keys,");
  my_putstr(1, "\n\t\tand turn the camera with the arrows.\n");
  my_putstr(1, "NIGHT MODE\n\t\tTurn on Nightmode by pressing 'N'. ");
  my_putstr(1, "Use flashlight with the 'F' key.\n\t\t");
  my_putstr(1, "To quit Nightmode, press 'B'.\n");
  my_putstr(1, "NOTES\n\t\tAn empty map file is considered as ");
  my_putstr(1, "nonexistent.\nAUTHOR\n\t\tMade by Mael Drapier\n");
}
