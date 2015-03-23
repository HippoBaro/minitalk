/*
** binary.c for Minitalk in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Wed Mar  4 00:00:55 2015 Hippolyte Barraud
** Last update Wed Mar  4 00:01:18 2015 Hippolyte Barraud
*/

#include "../../includes/client.h"

char	*get_binary(int pid, int coding)
{
  char	*str;
  int 	i;

  str = xmalloc((coding + 1) * sizeof(char));
  i = 0;
  while (i < (coding + 1))
    str[i++] = 0;
  i = 0;
  while (i < coding)
    {
      str[coding - 1 - i] = ((pid >> i) & 1) + 48;
      i++;
    }
  return (str);
}
