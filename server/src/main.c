/*
** main.c for minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Feb 27 21:40:07 2015 Hippolyte Barraud
** Last update Sat Mar 21 20:04:47 2015 Hippolyte Barraud
*/

#include "../../includes/server.h"

void	init_data(t_serv *ptr, bool force)
{
  ptr->c_pid = -1;
  ptr->error = FALSE;
  ptr->cs = 0;
  ptr->bitchar = 0;
  ptr->i = 0;
  ptr->bitint = 0;
  ptr->len = -1;
  ptr->n = 0;
  ptr->checksum = -1;
  g_data = ptr;
  if (force == TRUE)
    {
      free(g_data->str);
      g_data->str = NULL;
    }
}

void 	kill_safe(int pid, int signum)
{
  if (kill(pid, signum) == -1)
    init_data(g_data, TRUE);
}

int		main(void)
{
  t_serv	data;

  my_put_nbr(getpid());
  my_putstr("\n");
  data.str = NULL;
  init_data(&data, FALSE);
  if (signal(SIGUSR1, transaction_index) == SIG_ERR)
    print_error("Error : signal handling refused", TRUE);
  if (signal(SIGUSR2, transaction_index) == SIG_ERR)
    print_error("Error : signal handling refused", TRUE);
  pause();
  if (data.c_pid == -1)
    while (TRUE)
      pause();
  return (0);
}
