/*
** str_utils.c for minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Feb 27 21:39:37 2015 Hippolyte Barraud
** Last update Wed Mar  4 00:14:30 2015 Hippolyte Barraud
*/

#include "../../includes/common.h"

void	my_put_nbr(int nb)
{
  int	div;
  char  tmp;

  div = -1;
  tmp = '-';
  if (nb < 0)
    write(1, &tmp, 1);
  else
    nb = -nb;
  while ((nb / -div) <= -10)
    div = div * 10;
  while (div < 0)
    {
      tmp = (nb / div) + '0';
      write(1, &tmp, 1);
      nb = nb % div;
      div = div / 10;
    }
}

void	my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != 0)
    {
      write(1, &str[a], 1);
      a++;
    }
}

void	print_colored(char *str, char *color)
{
  my_putstr(color);
  my_putstr(str);
  my_putstr(BLANK);
}

static int	my_getnbrbis(int nbr, int idx, char *str)
{
  int		a;

  a = 0;
  while (str[idx] >= '0' && str[idx] <= '9')
    {
      nbr =  nbr * 10 + (str[idx] - '0');
      idx = idx + 1;
      if (str[idx] < '0' || str[idx] > '9')
	return (nbr);
    }
  if (nbr <= -2147483648 || nbr > 2147483647)
    return (a);
  else
    return (nbr);
}

int	my_getnbr(char *str)
{
  int	idx;
  int	nbr;
  int	neg;

  idx = 0;
  nbr = 0;
  neg = 1;
  while (str[idx] == '+' || str[idx] == '-')
    {
      if (str[idx] == '-')
	neg  = neg * - 1;
      idx = idx + 1;
    }
  if (str[idx] < '0' || str[idx] > '9')
    return (nbr);
  return (my_getnbrbis(nbr, idx, str) * neg);
}
