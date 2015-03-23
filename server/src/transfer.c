/*
** transfer.c for Minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Wed Mar  4 00:12:59 2015 Hippolyte Barraud
** Last update Wed Mar  4 00:13:23 2015 Hippolyte Barraud
*/

#include "../../includes/server.h"

void	fill_char(int signal)
{
  if (g_data->n > g_data->len)
    {
      handle_transfer_error();
      return;
    }
  if (signal == SIGUSR1)
    g_data->cs = (g_data->cs << 1) + 0;
  else
    g_data->cs = (g_data->cs << 1) + 1;
  g_data->bitchar++;
  if (g_data->bitchar == 8)
    {
      g_data->bitchar = 0;
      g_data->str[g_data->n++] = g_data->cs;
      if (g_data->cs == 0)
	transaction_completed();
      else
	{
	  g_data->cs = 0;
	  kill_safe(g_data->c_pid, SIGUSR1);
	}
    }
  else
    kill_safe(g_data->c_pid, SIGUSR1);
}

bool	fill_int(int signal, int *target)
{
  if (signal == SIGUSR1)
    g_data->i = (g_data->i << 1) + 0;
  else
    g_data->i = (g_data->i << 1) + 1;
  g_data->bitint++;
  if (g_data->bitint == 32)
    {
      *target = g_data->i;
      g_data->i = 0;
      g_data->bitint = 0;
      usleep(1000);
      kill_safe(g_data->c_pid, SIGUSR1);
      return (TRUE);
    }
  return (FALSE);
}
