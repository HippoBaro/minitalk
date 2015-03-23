/*
** transaction.c for Minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Wed Mar  4 00:12:38 2015 Hippolyte Barraud
** Last update Sat Mar 21 20:05:50 2015 Hippolyte Barraud
*/

#include "../../includes/server.h"

void	handle_transfer_error(void)
{
  g_data->error = TRUE;
  usleep(1000);
  kill_safe(g_data->c_pid, SIGUSR2);
  init_data(g_data, TRUE);
  g_data->error = TRUE;
}

void transaction_completed(void)
{
  if (g_data->checksum == hash(g_data->str))
    {
      my_putstr(HEADER_DATA);
      my_putstr(g_data->str);
      my_putstr("\n" FOOTER_DATA);
      kill_safe(g_data->c_pid, SIGUSR1);
      init_data(g_data, TRUE);
    }
  else
    handle_transfer_error();
}

void	transaction_index(int sig)
{
  if (signal(sig, transaction_index) == SIG_ERR)
    print_error("Error : signal handling refused", TRUE);
  if (g_data->c_pid == -1)
    fill_int(sig, &(g_data->c_pid));
  else if (g_data->len == -1)
    {
      if (fill_int(sig, &(g_data->len)))
	g_data->str = xmalloc(sizeof(char) * g_data->len + 10);
    }
  else if (g_data->checksum == -1)
    fill_int(sig, &(g_data->checksum));
  else
    fill_char(sig);
}
