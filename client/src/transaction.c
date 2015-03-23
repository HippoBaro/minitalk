/*
** transaction.c for Minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Wed Mar  4 00:06:36 2015 Hippolyte Barraud
** Last update Sat Mar 21 20:13:06 2015 Hippolyte Barraud
*/

#include "../../includes/client.h"

void	transaction_error(int sig)
{
  if (signal(sig, transaction_error) == SIG_ERR)
    print_error("Error : signal handling refused", TRUE);
  if (sig == SIGUSR2)
    {
      init_client(g_data->target_pid, g_data->string, g_data);
      print_error(ERROR_CORRUPTED_DATA, FALSE);
      sleep(1);
      init_transmision();
    }
}

void	transaction_completed()
{
  print_colored(TRANSFER_SUCCES, GREEN);
  if (g_data->bools.source_isfile)
    free(g_data->string);
  exit(EXIT_SUCCESS);
}

void	transaction_select(int signum)
{
  if (signal(SIGUSR1, transaction_select) == SIG_ERR)
    print_error("Error : signal handling refused", TRUE);
  if (g_data->bools.server_reached == FALSE)
    g_data->bools.server_reached = TRUE;
  if (g_data->bools.len_sent && g_data->bools.checksum_sent
      && g_data->bools.str_sent == FALSE)
    {
      print_stage(TRUE);
      send_char(signum);
    }
  else if (g_data->bools.len_sent == FALSE)
    {
      send_int32(g_data->len);
      g_data->bools.len_sent = TRUE;
    }
  else if (g_data->bools.checksum_sent == FALSE)
    {
      send_int32(g_data->checksum);
      g_data->bools.checksum_sent = TRUE;
      print_stage(FALSE);
    }
  else
    transaction_completed();
}

void	start_transaction()
{
  if (signal(SIGUSR1, transaction_select) == SIG_ERR)
    print_error("Error : signal handling refused", TRUE);
  if (signal(SIGUSR2, transaction_error) == SIG_ERR)
    print_error("Error : signal handling refused", TRUE);
  init_transmision();
  while (TRUE);
}

