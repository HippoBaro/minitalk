/*
** hash.c for minitalk in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Feb 27 21:39:26 2015 Hippolyte Barraud
** Last update Wed Mar  4 00:13:41 2015 Hippolyte Barraud
*/

#include "../../includes/common.h"

int	hash (const char *word)
{
  int	hash;
  int	i;

  i = hash = 0;
  while (word[i] != '\0')
    hash = 31 * hash + word[i++];
  return (hash);
}
