/*
** xmalloc.c for minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Feb 27 21:39:49 2015 Hippolyte Barraud
** Last update Wed Mar  4 00:14:52 2015 Hippolyte Barraud
*/

#include "../../includes/common.h"

void   	*xmalloc(size_t size)
{
  void 	*tab;

  tab = malloc(size);
  if (tab == NULL)
    print_error(ERROR_MALLOC, TRUE);
  return (tab);
}

void	print_error(char *descr, bool Critical)
{
  my_putstr(RED);
  my_putstr(descr);
  my_putstr(BLANK);
  if (Critical)
    exit(EXIT_FAILURE);
}
