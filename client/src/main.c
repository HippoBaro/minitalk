/*
** main.c for minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Feb 27 21:39:09 2015 Hippolyte Barraud
** Last update Wed Mar  4 00:05:07 2015 Hippolyte Barraud
*/

#include "../../includes/client.h"

void 	init_client(int pid, char *str, t_client *ptr)
{
  ptr->bools.server_reached = FALSE;
  ptr->string = str;
  ptr->bools.str_sent = FALSE;
  ptr->len = my_strlen(str);
  ptr->bools.len_sent = FALSE;
  ptr->target_pid = pid;
  ptr->i_byte = 0;
  ptr->i_bit = 0;
  ptr->bools.checksum_sent = FALSE;
  ptr->checksum = hash(str);
  ptr->bools.did_print_meta_comfirm = FALSE;
  ptr->stats.lastbytetransfered = 0;
  ptr->stats.lastrate = 0;
  ptr->stats.percent = -1;
  g_data = ptr;
}

void 	kill_safe(int pid, int signum)
{
  if (kill(pid, signum) == -1)
    print_error(ERROR_UNREACH, TRUE);
}

int		main(int ac, char **av)
{
  int		pid;
  t_client	ptr;
  char		*str;

  check_arg(ac, av);
  check_pid(av[1]);
  ptr.bools.source_isfile = FALSE;
  if ((pid = my_getnbr(av[1])) < 1)
    print_error(ERROR_INVALID_PID, TRUE);
  if ((str = try_readfile(av[2])) == NULL)
    init_client(pid, av[2], &ptr);
  else
    {
      ptr.bools.source_isfile = TRUE;
      init_client(pid, str, &ptr);
    }
  start_transaction();
  return (EXIT_SUCCESS);
}
