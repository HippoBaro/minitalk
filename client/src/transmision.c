/*
** transmision.c for Minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Wed Mar  4 00:07:11 2015 Hippolyte Barraud
** Last update Wed Mar  4 01:33:46 2015 Hippolyte Barraud
*/

#include "../../includes/client.h"

static bool	ping_pong(char c, int pid)
{
  char	       	*my_char;
  bool 		out;

  my_char = get_binary(c , 8);
  out = FALSE;
  if (my_char[g_data->i_bit] == '0')
    kill_safe(pid, SIGUSR1);
  else
    kill_safe(pid, SIGUSR2);
  g_data->i_bit++;
  if (g_data->i_bit == 8)
    {
      g_data->i_bit = 0;
      if (c != 0)
	g_data->i_byte++;
      else
	out = TRUE;
    }
  free(my_char);
  return (out);
}

bool	send_bin(char *bin)
{
  int  	n;

  n = 0;
  while (bin[n])
    {
      if (bin[n] == '0')
	{
	  if (kill(g_data->target_pid, SIGUSR1) == -1)
	    return (FALSE);
	}
      else
	if (kill(g_data->target_pid, SIGUSR2) == -1)
	  return (FALSE);
      n++;
      usleep(1000);
    }
  return (TRUE);
}

void	send_char(int signal)
{
  if (signal == SIGUSR1)
    {
      if (g_data->string[g_data->i_byte])
	ping_pong(g_data->string[g_data->i_byte], g_data->target_pid);
      else
	if (ping_pong('\0', g_data->target_pid) == TRUE)
	  g_data->bools.str_sent = TRUE;
    }
}

void	send_int32(int data)
{
  char 	*bin;
  int  	ret;

  bin = NULL;
  bin = get_binary(data, 32);
  ret = send_bin(bin);
  free(bin);
  if (ret == FALSE)
    print_error(ERROR_SERVER_UNREACH, TRUE);
}

void    init_transmision()
{
  int	pid;

  pid = getpid();
  print_pid(pid);
  send_int32(pid);
  sleep(5);
  if (g_data->bools.server_reached == FALSE)
    print_error(ERROR_TIMEOUT, TRUE);
}
