/*
** check_arg.c for minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Feb 27 21:38:56 2015 Hippolyte Barraud
** Last update Wed Mar  4 00:02:32 2015 Hippolyte Barraud
*/

#include "../../includes/client.h"

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != 0)
    a = a + 1;
  return (a);
}

void	check_arg(int ac, char **av)
{
  if (ac != 3)
    print_error(USAGE_BIN, TRUE);
  if (!av[1] || !av[2])
    print_error(USAGE_BIN, TRUE);
}

int	check_pid(char *pid)
{
  int	i;

  i = 0;
  while (pid[i])
    {
      if (pid[i] < '0' || pid[i] > '9')
	print_error(ERROR_INVALID_PID, TRUE);
      i++;
    }
  return (0);
}
